/*
 * Exercise 17.38: Extend your program from the previous exercise to print each
 * word you read onto its own line.
 *
 * By Faisal Saadatmand
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

char *charArrayRealloc(char *p, const size_t &oldSize, const size_t &newSize)
{
	// if p is a nullptr, allocate a new block.
	char *block = new char[newSize] ();
	if (!p)
		return block;
	// else reallocate: create a new block, copy data and clean up
	memcpy(block, p, oldSize);
	delete [] p;
	p = block;
	return p;
}

void releaseCharArray(char *p)
{
	delete [] p;
	p = nullptr;
}

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
	long size = 30, count = 0;
	char *p = new char[size];
	constexpr size_t stepSize = 25;
	while ((count = infile.getline(p, size, '\n').gcount())) {
		if (count == size - 1)  {
			p = charArrayRealloc(p, size, size + stepSize); 
			if (!p) {
				std::cerr << "Could not allocate memory\n";
				return EXIT_FAILURE;
			}
			infile.clear();
		}
		std::string word;
		std::stringstream stream(p);
		while (stream >> word)
			std::cout << word << '\n';
	}
	releaseCharArray(p);
	return 0;
}
