/*
 * Exercise 17.21: Rewrite your phone number program from § 8.3.2 (p. 323) to
 * use the valid function defined in this section.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

struct PersonInfo {
	std::string name;
	std::string phones;
};

bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (!m[4].matched || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

std::string format(const std::smatch &m)
{
	std::string formatted;
	for (decltype(m.size()) i = 1; i < m.size(); ++i) {
		if ((i == 1 || i == 3) && m[i].matched)
			continue;
		if ((i == 4 || i == 6) && m[4].str() == m[6].str()) {
				formatted.push_back('-');
				continue;
			}
		formatted += m[i].str();
	}
	return formatted;
}

int main()
{
	std::string line, rest;
	std::vector<PersonInfo> people;

	while (getline(std::cin, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		if (std::getline(record, rest)) // read the rest of the line;
			info.phones = rest;
		people.push_back(info);
	}
	std::string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	std::regex r(pattern);
	for (const auto &entry : people) {
		std::ostringstream formatted, badNum;
		for (std::sregex_iterator it(entry.phones.begin(),
					entry.phones.end(), r), end_it; it != end_it; ++it)
			if (!valid(*it))
				badNum << " " << it->str();
			else
				formatted << " " << format(*it);
		if (badNum.str().empty())
			std::cout << entry.name << " " << formatted.str() << '\n';
		else
			std::cerr << "input error: " << entry.name
					  << " invalid number(s) " << badNum.str() << '\n';
	}
	return 0;
}
