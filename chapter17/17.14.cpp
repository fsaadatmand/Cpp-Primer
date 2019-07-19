/*
 * Exercise 17.14: Write several regular expressions designed to trigger
 * various errors. Run your program to see what output your compiler generates
 * for each error.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string input;
	while (true) {
		std::cout << "Enter a regular expression: ";
		if (!(std::cin >> input) || input == "q")
			break;
		try {
			std::regex r(input);
		} catch (std::regex_error &e) {
			std::cerr << e.what() << "\ncode: " << e.code() << '\n';
			continue;
		}
		std::cout << "valid regex\n";
	}
	return 0;
}
