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
	std::vector<std::string> text;
	std::map<std::string, std::set<size_t>> words_map;
	std::map<std::string, std::set<size_t>>::const_iterator iter_words;
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

TexQuery &query(const std::string &s, TexQuery &data){

	data.iter_words = data.words_map.find(s);
	if (data.iter_words == data.words_map.end())
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
	os << data.iter_words->first << " occurs " << data.count
	   << ((data.count > 1) ? " times" : " time") << std::endl;
	for (auto const &l : data.iter_words->second)
		os << "(line " << l << ") " << data.text[l - 1] << '\n';
	return os;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " infile\n";
		return -1;
	}
	std::ifstream infile(*++argv);
	if (!infile) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	TexQuery fileData;
	loadFile(infile, fileData);
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, query(s, fileData));
	}
	return 0;
}
