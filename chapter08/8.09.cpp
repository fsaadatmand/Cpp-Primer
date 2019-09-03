/*
 * Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2
 * (p. 314) to print the contents of an istringstream object.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>

std::istream &printWords(std::istream &);

std::istream &printWords(std::istream &is)
{
	std::string word;
	while (is >> word)
		std::cout << word << '\n';
	is.clear();
	return is;
}

int main()
{
	std::string line;
	while (getline(std::cin, line)) {
		std::istringstream iss(line);
		printWords(iss);
	}
	return 0;
}
