/*
 * Exercise 19.20: Nest your QueryResult class inside TextQuery and rerun the
 * programs you wrote to use TextQuery in § 12.3.2 (p. 490).
 *
 * By Faisal Saadatmand
 */

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

void excludePunctuation(std::string &);   // see exercise 11.4
class TextQuery {
	public:
		class QueryResult;
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
			excludePunctuation(word);
			auto &lines = wm[word];    // lines is a shared pointer
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class TextQuery::QueryResult {
	friend std::ostream& operator<<(std::ostream &, const QueryResult &);
	public:
		QueryResult(std::string s,
			        std::shared_ptr<std::set<line_no>> p,
					std::shared_ptr<std::vector<std::string>> f) :
			        sought(s), lines(p), file(f) {}
		std::set<line_no>::iterator begin() const { return lines->begin(); }
		std::set<line_no>::iterator end() const { return lines->end(); }
		std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
};

TextQuery::QueryResult
TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	return QueryResult(sought, loc->second, file);
}

void excludePunctuation(std::string &s)
{
	if (s.size() <= 1) // avoid double erase 
		return;
	if (ispunct(s.front()))
		s.erase(0, 1);
	if (ispunct(s.back()))
		s.pop_back();
}

std::string make_plural(std::size_t ctr, const std::string &word,
		                             const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream& operator<<(std::ostream &os, const TextQuery::QueryResult &qr)
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
	std::cout << tq.query(s) << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <file name>\n";
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
