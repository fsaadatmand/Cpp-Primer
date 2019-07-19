/*
 * Exercise 17.15: Write a program using the pattern that finds words that
 * violate the "i before e except after c" rule. Have your program prompt the
 * user to supply a word and indicate whether the word is okay or not. Test
 * your program with words that do and do not violate the rule.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string word;
	std::string pattern("[^c]ie");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	std::regex r(pattern, std::regex::icase);
	std::smatch result;
	std::cout << "RULE: \"i before e, except after c\"\n";
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
