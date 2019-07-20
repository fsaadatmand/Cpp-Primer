/*
 * Exercise 17.22: Rewrite your phone program so that it allows any number of
 * whitespace characters to separate the three parts of a phone number.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <regex>

bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (!m[4].matched || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	std::string phone = "(\\()?(\\d{3})(\\))?([-.\\s])?(\\d{3})([-.\\s])?(\\d{4})";
	std::regex r(phone);
	std::string number;
	while (std::getline(std::cin, number) && number != "q") {
		for (std::sregex_iterator it (number.begin(), number.end(), r), end_it;
				it != end_it; ++it)
			if (valid(*it))
				std::cout << "Valid: " << it->str() << '\n';
			else
				std::cout << "not valid: " << it->str() << '\n';
	}
	return 0;
}
