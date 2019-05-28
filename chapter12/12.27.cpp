/*
 * Exercise 12.27: The TextQuery and QueryResult classes use only capabilities
 * that we have already covered. Without looking ahead, write your own versions
 * of these classes.
 *
 * By Faisal Saadatmand
 */

#include <fstream>
#include <iostream>
#include "TextQuery.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " infile\n";
		return -1;
	}
	std::ifstream infile(*++argv);
	if (!infile) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	TextQuery tq(infile);
	while (true) {
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}
	return 0;
}
