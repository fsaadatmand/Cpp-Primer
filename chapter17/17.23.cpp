/*
 * Exercise 17.23: Write a regular expression to find zip codes. A zip code can
 * have five or nine digits. The first five digits can be separated from the
 * remaining four by a dash.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string pattern("^\\d{5}(?:-\\d{4})?$");
	std::regex r(pattern);
	std::smatch result;
	std::string line;
	while (std::getline (std::cin, line) && line != "q")
		if (std::regex_match(line, result, r))
			std::cout << result.str() << '\n';
	return 0;
}
