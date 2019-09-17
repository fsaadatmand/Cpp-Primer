/*
 * Exercise 17.37: Use the unformatted version of getline to read a file a line
 * at a time. Test your program by giving it a file that contains empty lines
 * as well as lines that are longer than the character array that you pass to
 * getline.
 *
 * By Faisal Saadatmand
 */

/*
 * The purpose of this exercise seems to emphasise the limitation of the
 * unformatted getline. If you are interested to see how to overcome some, but
 * not all, of these limitations, see 17.37a.cpp
 *
 * When an empty line is read, getline will read up to the newline character,
 * which will be counted but not inserted into the buffer array.
 *
 * If a line that is longer than the buffer array is read, getline will read
 * up to size - 1 character and, thereafter, the failbit will be set. In which
 * case, the stream will not read any further character. ()
  */

#include <fstream>
#include <iostream>
#include <string>

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
	constexpr std::size_t size = 24;
	char buffer[size];
	unsigned long lineNo = 1;
	while (infile.getline(buffer, size)) {
		std::cout << std::string(buffer) << '\n';
		++lineNo;
	}
	if (infile.fail() && infile.gcount()) {
		std::cerr << "\nfailbit: ON\n"
				  << "line number: " << lineNo << '\n'
				  << "buffer size: " << size << '\n'
				  << "characters read: " << infile.gcount() << '\n';
	}
	return 0;
}
