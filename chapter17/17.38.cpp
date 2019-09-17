/*
 * Exercise 17.38: Extend your program from the previous exercise to print each
 * word you read onto its own line.
 *
 * By Faisal Saadatmand
 */

/*
 * NOTE: see 17.38a.cpp for dynamically allocated buffer (i.e. line)
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <filename>\n";
		return EXIT_FAILURE;
	}
	std::ifstream infile(*++argv);
	if (!infile) {
		std::cerr << "Cannot open file" << *++argv << '\n';
		return EXIT_FAILURE;
	}
	std::streamsize size = 100;
	char buffer[size];
	while (infile.getline(buffer, size, ' ')) {
		std::string word;
		std::stringstream stream(buffer);
		while (stream >> word)
			std::cout << word << '\n';
	}
	return 0;
}
