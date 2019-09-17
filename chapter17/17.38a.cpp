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

template <typename T>
void release(T *p)
{
	delete [] p;
	p = nullptr;
}

template <typename T, typename U>
T* reallocate(T* p, U oldSize, U newSize)
{
	auto newBlock = new T[newSize];
	if (p && newBlock) {        // not a nullptr? reallocate
		memcpy(newBlock, p, oldSize);
		release(p);
	}
	return newBlock;
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
	std::streamsize size = 0, oldSize = 0, count = 0;
	constexpr std::streamsize stepSize = 100;
	char *p = nullptr;
	do {
		if (infile.gcount() == size - 1 || !size)  {
			oldSize = size;
			size += stepSize;
			if (!(p = reallocate(p, oldSize, size))) {
				std::cerr << "Could not allocate memory\n";
				return EXIT_FAILURE;
			}
			infile.clear(); // reset infile to a valid state
			++count;
		}
		if (count) { // skip the first uninitialized allocation
			std::string word;
			std::stringstream stream(p);
			while (stream >> word)
				std::cout << word << '\n';
		}
	} while (infile.getline(p, size).gcount());
	release(p);
	return 0;
}
