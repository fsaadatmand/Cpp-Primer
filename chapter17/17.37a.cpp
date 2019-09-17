/*
 * Exercise 17.37: Use the unformatted version of getline to read a file a line
 * at a time. Test your program by giving it a file that contains empty lines
 * as well as lines that are longer than the character array that you pass to
 * getline.
 *
 * By Faisal Saadatmand
 */

/*
 *
 * The purpose of this exercise seems to emphasises the limitation of the
 * unformatted getline. This program overcomes these limitations by
 * implementing a dynamically growing char array to store the input from the
 * unformatted getline. This approach is often used in C. In C++, however, it
 * is recommended to use the standard library getline instead.
 *
 * Here, we implement a dynamically growing char array to store the input from
 * the unformatted getline. If the character count read from the getline is
 * greater than the size of the buffer, we reallocated the buffer array by the
 * value of stepSize.
 *
 * Issue: the stepSize at the first iteration must be big enough to hold the
 * anticipated character count to be read by getline, otherwise we would face
 * the same issue we would had with a statically allocated buffer, which would
 * set the failbit.
 *
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

template <typename T>
void release(T *p)
{
	delete [] p;
	p = nullptr;
}

template <typename T>
T* reallocate(T* p, std::size_t oldSize, std::size_t newSize)
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
	constexpr std::streamsize stepSize = 5;
	char *p = nullptr;
	do {
		// reallocate char array if it is full or unallocated initially
		if (infile.gcount() >= size - 1 || !p)  {
			oldSize = size;
			size += stepSize;
			if (!(p = reallocate(p, oldSize, size))) {
				std::cerr << "Could not allocate memory\n";
				return EXIT_FAILURE;
			}
			infile.clear(); // reset the ifstream to a valid state
			if (count) { // skip the first uninitialized allocation
				std::cout << std::string(p); // print without newline char
				if (infile.gcount() == oldSize)
					std::cout << '\n';
			}
			++count;
		} else
			std::cout << std::string(p) << '\n';

	} while (infile && infile.getline(p, size).gcount());
	release(p);
	return 0;
}
