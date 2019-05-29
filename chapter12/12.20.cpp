/*
 * Exercise 12.20: Write a program that reads an input file a line at a time
 * into a StrBlob and uses a StrBlobPtr to print each element in that StrBlob.
 *
 * By Faisal Saadatmand
 */

#include <fstream>
#include <iostream>
#include <string>
#include "StrBlob.h"

int main(int argc, char **argv)
{

	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " inFile" << std::endl;
		return -1;
	}

	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "Couldn't open " << *argv << std::endl;
		return -1;
	}

	StrBlob text;
	std::string line;
	while (getline(inFile, line))
			text.push_back(line);

	// Since we do not have != operator overload for StrBlobPtr, we have to
	// iterate StrBlob text using an index while simultaneously incrementing
	// the weak_ptr.
	StrBlobPtr beg = text.begin();   // could've used auto here
	for (size_t i = 0; i != text.size(); ++i) {
		std::cout << beg.deref() << '\n';
		beg.incr();
	}

	return 0;
}
