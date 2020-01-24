/*
 * Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2
 * (p. 314) to print the contents of an istringstream object.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>

std::istream& printInput(std::istream &is)
{
	std::string line;
	while (getline(is, line))
		std::cout << line << '\n';
	is.clear();
	return is;
}

int main()
{
	std::string line;
	while (getline(std::cin, line)) {
		std::istringstream iss(line);
		printInput(iss);
	}
	return 0;
}
