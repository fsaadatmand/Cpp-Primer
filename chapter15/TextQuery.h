#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

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
class QueryResult;
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
			excludePunctuation(word);
			auto &lines = wm[word];    // lines is a shared pointer
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult {
	friend std::ostream& operator<<(std::ostream &, const QueryResult &);
	public:
		QueryResult(std::string s,
			        std::shared_ptr<std::set<TextQuery::line_no>> p,
					std::shared_ptr<std::vector<std::string>> f) :
			        sought(s), lines(p), file(f) {}
		std::set<TextQuery::line_no>::iterator
			begin() const { return lines->begin(); }
		std::set<TextQuery::line_no>::iterator
			end() const { return lines->end(); }
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

std::ostream& operator<<(std::ostream &os, const QueryResult &qr)
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
#endif
