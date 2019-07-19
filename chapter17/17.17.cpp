/*
 * Exercise 17.17: Update your program so that it finds all the words in an
 * input sequence that violiate the “ei” grammar rule.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string line;
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::smatch result;
	while (std::getline(std::cin, line)) {
		for (std::sregex_iterator it(line.begin(), line.end(), r), end_it;
				it != end_it; ++it) {
			auto pos = it->prefix().length();
			pos = pos > 40 ? pos - 40 : 0;
			std::cout << it->prefix().str().substr(pos)
				<< "\n\t\t>>> " << it->str() << " <<<\n"
				<< it->suffix().str().substr(0, 40) << '\n';
		}
	}
	return 0;
}
