/*
 * Exercise 8.4: Write a function to open a file for input and read its
 * contents into a vector of strings, storing each line as a separate element
 * in the vector.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

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
		std::cerr << "Usage: " << *argv << " <input_file>\n";
		return EXIT_FAILURE;
	}
	auto p = ++argv;
	std::vector<std::string> file = loadFile(*p);
	for (const auto &elem : file)
		std::cout << elem << '\n';
	return 0;
}
