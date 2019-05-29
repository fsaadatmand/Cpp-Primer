/*
 * Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use a
 * StrBlob instead of a vector<string> to hold the input file.
 *
 * By Faisal Saadatmand
 *
 * Note: StrBlob required a cbegin and cend operations.
 */

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>
#include "StrBlob.h"

class QueryResult;
class TextQuery {
	friend class QueryResult;
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream &);
		QueryResult query(const std::string &) const;
	private:
		StrBlob file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is)
{
	std::string text;
	while (getline(is, text)) {
		file.push_back(text);
		int n = file.size() - 1;
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
	friend std::ostream& print (std::ostream&, const QueryResult&);
	public:
		using line_no = std::vector<std::string>::size_type;
		QueryResult(std::string s,
			        std::shared_ptr<std::set<line_no>> p,
					StrBlob f) :
			        sought(s), lines(p), file(f) {}
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		StrBlob file;
};

QueryResult
TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file); // not found
	auto test = file.cbegin();
	return QueryResult(sought, loc->second, file);
}

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
		os << "\t(line " << num + 1 << ") ";
		auto line = qr.file.cbegin();
		for (decltype(qr.file.size()) i = 0; i != num; ++i)
			line.incur();
		 os << line.deref() << std::endl;
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
