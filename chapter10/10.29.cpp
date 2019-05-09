/*
 * Exercise 10.29: Write a program using stream iterators to read a text file
 * into a vector of strings.
 *
 * By Faisal Saadatmand
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>


int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usag: " << *argv << " file\n";
		return -1;
	}
	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "Could not open " << *argv << '\n';
		return -1;
	}
	std::istream_iterator<std::string> in_iter(inFile), eof;
	std::vector<std::string> text(in_iter, eof);
	
	for (const auto word : text)
		std::cout << word << ' ';
	std::cout << '\n';
	return 0;
}
