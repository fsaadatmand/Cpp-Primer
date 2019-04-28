/*
 * Exercise 8.2: Test your function by calling it, passing cin as an argument.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
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
	printWords(std::cin);
	return 0;
}
