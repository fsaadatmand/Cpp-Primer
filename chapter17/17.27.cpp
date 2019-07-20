/*
 * Exercise 17.27: Write a program that reformats a nine-digit zip code as
 * ddddd-dddd.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string pattern("^(\\d{5})(\\d{4})$");
	std::regex r(pattern);
	std::string fmt = "$1-$2";
	std::string line;
	while (std::getline (std::cin, line) && line != "q") {
		using std::regex_constants::format_no_copy;
		std::string formatted(std::regex_replace(line, r, fmt, format_no_copy));
		if (!formatted.empty())
			std::cout << formatted << '\n';
	}
	return 0;
}
