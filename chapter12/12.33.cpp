/*
 * Exercise 12.33: In Chapter 15 we'll extend our query system and will need
 * some additional members in the QueryResult class. Add members named begin
 * and end that return iterators into the set of line numbers returned by a
 * given query, and a member named get_file that returns a shared_ptr to the
 * file in the QueryResult object.
 *
 * By Faisal Saadatmand
 */

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

class QueryResult;
class QueryResultPtr;
class TextQuery {
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream &);
		QueryResult query(const std::string &) const;
	private:
		std::shared_ptr<std::vector<std::string>> file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];    // lines is a shared pointer
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult {
	friend class QueryResultPtr;
	friend std::ostream& print (std::ostream&, const QueryResult&);
	public:
		QueryResult(std::string s,
			        std::shared_ptr<std::set<TextQuery::line_no>> p,
					std::shared_ptr<std::vector<std::string>> f) :
			        sought(s), lines(p), file(f) {}
		QueryResultPtr begin() const;
		QueryResultPtr end() const;
		QueryResultPtr shared_ptr() const;
		std::shared_ptr<std::vector<std::string>>
			get_file() const { return file; }
	private:
		std::string sought;
		std::shared_ptr<std::set<TextQuery::line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
};

QueryResult
TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	return QueryResult(sought, loc->second, file);
}

class QueryResultPtr {
	public:
		QueryResultPtr() : curr(0) {}
		QueryResultPtr(const QueryResult &a, size_t sz = 0) :
			wptr(a.lines), curr(sz) {}
		const TextQuery::line_no& deref() const;
		QueryResultPtr& incr();
	private:
		std::shared_ptr<std::set<TextQuery::line_no>>
			check(std::size_t, const std::string &msg) const;
		std::weak_ptr<std::set<TextQuery::line_no>> wptr;
		size_t curr;
};

std::shared_ptr<std::set<TextQuery::line_no>>
QueryResultPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound QueryResultPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

const TextQuery::line_no&
QueryResultPtr::deref() const
{
	auto p = check(curr, "dereference past end");

	auto iter = p->begin();
	for (TextQuery::line_no i = 0; i != curr; ++i)
		++iter;
	return *iter;
}

QueryResultPtr&
QueryResultPtr::incr()
{
	check(curr, "increment past end of QueryResultPtr");
	++curr;
	return *this;
}

QueryResultPtr QueryResult::begin() const { return QueryResultPtr(*this); }
QueryResultPtr QueryResult::end() const { return QueryResultPtr(*this); }

std::string make_plural(std::size_t ctr, const std::string &word,
		                             const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
			<< (*qr.get_file())[num] << std::endl;  // use get_file instead
	}
	return os;
}

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	while (true) {
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " infile\n";
		return -1;
	}
	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	runQueries(inFile);
	return 0;
}
