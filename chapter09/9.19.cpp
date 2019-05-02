/*
 * Exercise 9.19: Rewrite the program from the previous exercise to use a list.
 * List the changes you needed to make.
 *
 * Changes: list can use the exact same code.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <list>

int main()
{
	std::string word;
	std::list<std::string> listOfWords;

	while (std::cin >> word)
		listOfWords.push_back(word);
		
	for (auto it = listOfWords.cbegin(); it != listOfWords.cend(); ++it)
		std::cout << *it << "\n";

	return 0;
}
