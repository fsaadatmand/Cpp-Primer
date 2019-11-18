/*
 * Exercise 6.25: Write a main function that takes two arguments. Concatenate
 * the supplied arguments and print the resulting string.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string str;
	if (argc != 3) {
		std::cerr << "Usage: "  << *argv << " <arg1> <arg2>\n";
		return -1;
	}
	while (--argc > 0)       // iterate through the cli arguments
		str += *++argv;      // concatenate strings
	std::cout << str << '\n';
	return 0;
}
