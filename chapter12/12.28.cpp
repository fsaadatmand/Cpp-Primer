/*
 * Exercise 12.28: Write a program to implement text queries without defining
 * classes to manage the data. Your program should take a file and interact
 * with a user to query for words in that file. Use vector, map, and set
 * containers to hold the data for the file and to generate the results for the
 * queries.
 *
 * By Faisal Saadatmand
 *
 * Note: though I am using a struct, it is used as a grouping variable for a
 * collection of related data. As such, the struct lacks all the facilities of
 * by a proper class.
 *
 */

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

struct TexQuery {
	using line_no = std::vector<std::string>::size_type;
	std::vector<std::string> text;
	std::map<std::string, std::set<line_no>> words_map;
	std::map<std::string, std::set<line_no>>::const_iterator lines;
	unsigned count = 0;
};

void loadFile(std::ifstream &file, TexQuery &data)
{
	std::string line, word;
	for (size_t ln = 1; getline(file, line); ++ ln) {
		data.text.push_back(line);
		std::istringstream iss(line);
		while (iss >> word)
			data.words_map[word].insert(ln);
	}
}

TexQuery &query(const std::string &s, TexQuery &data)
{
	data.lines = data.words_map.find(s);
	if (data.lines == data.words_map.end())
		data.count = 0;
	else {
		std::string word;
		for (auto const &line : data.text) {
			std::istringstream iss(line);
			while (iss >> word)
				if (word == s)
					++data.count;
		}
	}
	return data;
}

std::ostream& print(std::ostream &os, const TexQuery &data)
{
	if (!data.count)
		return os << "not found\n";
	os << data.lines->first << " occurs " << data.count
	   << ((data.count > 1) ? " times" : " time") << std::endl;
	for (auto const &n : data.lines->second)
		os << "(line " << n << ") " << data.text[n - 1] << '\n';
	return os;
}

void runQueries(std::ifstream &infile)
{
	TexQuery fileData;
	loadFile(infile, fileData);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, query(s, fileData));
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " infile\n";
		return -1;
	}
	std::ifstream file(*++argv);
	if (!file) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	runQueries(file);
	return 0;
}
