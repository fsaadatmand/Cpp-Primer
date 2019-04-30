/*
 * Exercise 8.10: Write a program to store each line from a file in a
 * vector<string>.  Now use an istringstream to read each element from the
 * vector a word at a time.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::istream &printWords(std::istream &);

std::istream &printWords(std::istream &is)
{
	std::string word;
	while (is >> word)
		std::cout << word << '\n';
	is.clear();
	return is;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " + std::string(*argv) + " file\n";
		return -1;
	}

	auto p = argv + 1;
	std::ifstream infile(*p);
	if (!infile) {
		std::cerr << "Couldn't open " + std::string(*p) << '\n';
		return -1;
	}

	std::string line;
	std::vector<std::string> content;
	while (infile >> line)
		content.push_back(line);

	std::string word;
	for (const auto &element : content) {
		std::istringstream word(element);
		printWords(word);
	}
	return 0;
}
