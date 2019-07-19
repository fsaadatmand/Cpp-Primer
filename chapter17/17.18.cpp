/*
 * Exercise 17.18: Revise your program to ignore words that contain “ei” but
 * are not misspellings, such as “albeit” and “neighbor.”
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <set>
#include <string>
#include <regex>

int main()
{
	std::set<std::string> exceptions{"albeit", "being", "neigbour", "veil"};
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::string line;
	while (std::getline(std::cin, line)) {
		for (std::sregex_iterator it(line.cbegin(), line.cend(), r), end_it;
				it != end_it; ++it) {
			auto skip = exceptions.find(it->str()); 
			if (skip != exceptions.cend())
				continue;
			auto pos = it->prefix().length();
			pos = pos > 40 ? pos - 40 : 0;
			std::cout << it->prefix().str().substr(pos)
				<< "\n\t\t>>> " << it->str() << " <<<\n"
				<< it->suffix().str().substr(0, 40) << '\n';
		}
	}
	return 0;
}
