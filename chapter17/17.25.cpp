/*
 * Exercise 17.25: Rewrite your phone program so that it writes only the first
 * phone number for each person.
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
	using std::regex_constants::format_first_only;
	using std::regex_constants::format_no_copy;
	while (std::getline(std::cin, s) || s == "q")
		std::cout << std::regex_replace(s, r, fmt,
				format_no_copy | format_first_only) << '\n';
	return 0;
}
