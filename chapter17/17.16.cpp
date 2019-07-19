/*
 * Exercise 17.16: What would happen if your regex object in the previous
 * program were initialized with "[^c]ei"? Test your program using that pattern
 * to see whether your expectations were correct.
 *
 * By Faisal Saadatmand
 */

/*
 * Answer: the spelling rule would become "e before i, except after c"
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string word;
	std::string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::smatch result;
	std::cout << "RULE: \"e before i, except after c\"\n";
	while (true) {
		std::cout << "Enter word: ";
		if (!(std::cin >> word) || word == "q")
			break;
		if (std::regex_search(word, result, r))
			std::cout << "okay!\n";
		else
			std::cout << "not okay\n";
	}
	return 0;
}
