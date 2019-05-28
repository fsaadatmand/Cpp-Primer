/*
 * Exercise 12.24: Write a program that reads a string from the standard input
 * into a dynamically allocated character array. Describe how your program
 * handles varying size inputs. Test your program by giving it a string of data
 * that is longer than the array
 *
 * By Faisal Saadatmand
 *
 * In the context of this program, a string is a set made of non-whitespace
 * characters that are contiguous.
 *
 * str is a pointer to the dynamically allocated array. length is the number of
 * elements in the array and stepSize is a const by which we can grow the array
 * length. i is a counter that has a twofold usage: to check the number of
 * characters read so far and to hold the current position in array.
 *
 * The program reads a character at a time (including whitespaces) from the
 * standard input. If there is enough memory in the str, it writes the
 * currently read character into it and increments i with the postfix operator,
 * otherwise it calls charArrayRealloc to (re)allocate memory. Note: length
 * starts at 0, which satisfies the if statement's condition at the first
 * iteration. Finally, the program prints str to the standard output.
 *
 * Inside the if statement, length is incremented by stepSize. The function
 * charArrayRealloc is called with str, the old length and the new length of
 * the str. Inside charArrayRealloc, we check if this is the first time the
 * function is called. In which case, a new block is allocated and a pointer to
 * it is returned, otherwise the memory is reallocated using the passed
 * arguments and a pointer to the new memory location is returned; the old
 * block is deleted. After the function has finished, we proceed with copying
 * characters into the array until we need to allocate more memory again. This
 * approach handles a string input of any size provided that the system has
 * enough memory. In the case that the new expression cannot allocate memory,
 * the program prints an error message to cerr and exits prematurely.
 */

#include <cctype>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>

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

// read a string into a dynamically allocated array.
int main()
{
	char ch, *str = nullptr;
	constexpr size_t stepSize = 25;
	size_t length = 0, i = 0;
	while (std::cin >> ch >> std::noskipws && !isspace(ch)) {
		if (i == length) {       // need more memory
			length += stepSize;  // grow the size of str
			str = charArrayRealloc(str, i, length);
			if (!str) {
				std::cerr << "Could not allocate memory\n";
				return -1;
			}
		}
		str[i++] = ch;
	}
	str[i] = '\0';
	std::cout << std::string(str) << std::endl;
	delete [] str;
	str = nullptr;               // good practice
	return 0;
}
