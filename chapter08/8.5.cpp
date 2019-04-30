/*
 * Exercise 8.5: Rewrite the previous program to store each word in a separate
 * element.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> &readFileIntoVector(std::string, std::vector<std::string> &);

std::vector<std::string> &readFileIntoVector(std::string file, std::vector<std::string> &v)
{
	std::string word;

	std::ifstream input(file);
	if (input) {
		while (input >> word)
			v.push_back(word);
	} else {
		std::cerr << "counldn't open: " + file << '\n';
		exit(EXIT_FAILURE);            // C-style exit
	}

	return v;
}

int main(int argc, char **argv)
{
	std::vector<std::string> content;

	if (argc < 2)
		std::cerr << "Usage: " << *argv << " file1 file2 ... \n";

	for (auto p = argv + 1; p != argv + argc; ++p)
		content = readFileIntoVector(*p, content);

	for (const auto &element : content)
		std::cout << element << '\n';
	return 0;
}
