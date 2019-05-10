/*
 * Exercise 10.42: Reimplement the program that eliminated duplicate words that
 * we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <list>

int main()
{
	std::list<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle"};
	words.sort();
	words.unique();
	for (const auto &elem : words)
		std::cout << elem << ' ';
	std::cout << std::endl;
	return 0;
}
