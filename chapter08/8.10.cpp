/*
 * Exercise 8.10: Write a program to store each line from a file in a
 * vector<string>. Now use an istringstream to read each element from the
 * vector a word at a time.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> loadFile(const std::string &file)
{
	std::ifstream input(file);
	if (!input) {
		std::cerr << "counldn't open: " + file << '\n';
		exit(EXIT_FAILURE); // C-style exit
	}
	std::vector<std::string> data;
	std::string line;
	while (getline(input, line))
		data.push_back(line);
	return data;
}

int main(int argc, char **argv)
{
	if (--argc != 1) {
		std::cerr << "Usage: " + std::string(*argv) + " <filename>\n";
		return -1;
	}
	auto p = argv + 1;
	std::vector<std::string> file = loadFile(*p);
	for (const auto &line : file) {
		std::istringstream ss(line);
		std::string word;
		while (ss >> word)
			std::cout << word << '\n';
	}
	return 0;
}
