/*
 * Exercise 8.2: Test your function by calling it, passing cin as an argument.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
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
	printInput(std::cin);
	if (std::cin.fail()) // check that the stream has been rested
		std::cout << "The stream is not in a good state\n";
	return 0;
}
