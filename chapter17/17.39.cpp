/*
 * Exercise 17.39: Write your own version of the seek program presented in this
 * section.
 *
 * By Faisal Saadatmand
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
	std::fstream inOut(*++argv,
			std::fstream::ate | std::fstream::in | std::fstream::out);
	if (!inOut) {
		std::cerr << "Cannot open file" << *++argv << '\n';
		return EXIT_FAILURE;
	}
	auto end_mark = inOut.tellg(); // original EOF position
	inOut.seekg(0, std::fstream::beg);
	std::size_t count = 0;
	std::string line;
	while (inOut && inOut.tellg() != end_mark
			&& std::getline(inOut, line)) {
		count += line.size() + 1; // 1 for newline char
		auto mark = inOut.tellg(); // read postion
		inOut.seekp(0, std::fstream::end);
		inOut << count;
		if (mark != end_mark)
			inOut << " ";
		inOut.seekg(mark);
	}
	inOut.seekp(0, std::fstream::end);
	inOut << "\n";
	return 0;
}
