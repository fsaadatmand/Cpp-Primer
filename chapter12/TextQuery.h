#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <sstream>
#include <map>
#include <memory>
#include <set>
#include <fstream>
#include <vector>

class TextQuery;

class QueryResult {
	public:
		friend std::ostream& print(std::ostream &os, const QueryResult &result);
		QueryResult() = default;
		QueryResult(std::shared_ptr<std::vector<std::string>> l,
				std::map<std::string, std::set<size_t>>::iterator r, unsigned n)
			    : lines(l), it_map(r), count(n) {}
	private:
		std::shared_ptr<std::vector<std::string>> lines;
		std::map<std::string,std::set<size_t>>::const_iterator it_map;
		unsigned count = 0;
};

class TextQuery {
	public:
		using vector_tq = std::vector<std::string>; 
		using map_tq = std::map<std::string, std::set<size_t>>; 
		friend class QueryResult;
		friend std::ifstream& read(std::ifstream &infile, TextQuery &data);
		TextQuery() : text(std::make_shared<vector_tq>()),
		                   words(std::make_shared<map_tq>()) {}
		TextQuery(std::ifstream &infile) : TextQuery() { read(infile, *this); };
		QueryResult query (const std::string &s) const;
	private:
		std::shared_ptr<vector_tq> text;
		std::shared_ptr<map_tq> words;
};

// members
QueryResult
TextQuery::query(const std::string &s) const
{
	auto it_words = words->find(s);
	if (it_words == words->end())
		return {};
	unsigned count = 0;
	std::string word;
	for (auto const &line : *text) {
		std::istringstream iss(line);
		while (iss >> word)
			if (word == s)
				++count;
	}
	return {text, it_words, count};
}

// non-members
std::ostream&
print(std::ostream &os, const QueryResult &result)
{
	if (!result.count)
		return os << "not found\n";

	os << result.it_map->first << " occurs " << result.count
	   << ((result.count > 1) ? " times" : " time") << std::endl;
	for (auto const &l : result.it_map->second)
		os << "(line " << l << ") " << result.lines->at(l - 1) << '\n';
	return os;
}

std::ifstream&
read(std::ifstream &infile, TextQuery &content)
{
	std::string line, word;
	for (size_t lineNumber = 1; getline(infile, line); ++lineNumber) {
		content.text->push_back(line);
		std::istringstream iss(line);
		while (iss >> word)
			(*content.words)[word].insert(lineNumber);
	}
	return infile;
}
#endif
