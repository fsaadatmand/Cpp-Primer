/*
 * Exercise 17.24: Write your own version of the program to reformat phone
 * numbers.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex r(phone);
	std::string fmt = "$2.$5.$7";
	std::string s;
	while (std::getline(std::cin, s) || s == "q")
		std::cout << std::regex_replace(s, r, fmt) << '\n';
	return 0;
}
