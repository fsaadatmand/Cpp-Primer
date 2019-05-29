/*
 * Exercise 12.29: We could have written the loop to manage the interaction
 * with the user as a do while (§ 5.4.4, p. 189) loop. Rewrite the loop to use
 * a do while. Explain which version you prefer and why.
 *
 * By Faisal Saadatmand
 *
 * The infinite loop and break statement version is cleaner.
 */

#include <fstream>
#include <iostream>
#include "TextQuery.h"

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	std::string s;
	bool quit = false;
	do {
		std::cout << "Enter word to look for, or q to quit: ";
		if(!(std::cin >> s) || s == "q")
			quit = true;
		else
			print(std::cout, tq.query(s)) << std::endl;
	} while (!quit);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " file\n";
		return -1;
	}
	std::ifstream file(*++argv);
	if (!file) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	runQueries(file);
	return 0;
}
