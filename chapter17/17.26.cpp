/*
 * Exercise 17.26: Rewrite your phone program so that it writes only the second
 * and subsequent phone numbers for people with more than one phone number.
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
	std::smatch m;
	using std::regex_constants::format_first_only;
	while (std::getline(std::cin, s) || s == "q") {
		if (std::regex_search(s, m, r))
			if (!m.suffix().str().empty())  // skip people with only one phone #
				std::cout << m.prefix()
					<< std::regex_replace(m.suffix().str().substr(1), r, fmt)
					<< '\n';
	}
	return 0;
}
