/*
 * Exercise 9.41: Write a program that initializes a string from a
 * vector<char>.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<char> cvec{'I', '\'', 'm', ' ', 'c', 'h', 'a', 'r', ' ',
		                   'v', 'e', 'c', 't', 'o', 'r'};
	// see tables 9.6 (p.347) and 9.11 (p.360)
	std::string s1(&cvec[0], cvec.size());
	//or
	// see table 9.4 (p.338)
	std::string s2(cvec.begin(), cvec.end());

	std::cout << "s1: ";
	for (const auto &elem : s1)
		std::cout << elem;
	std::cout << '\n';

	std::cout << "s2: ";
	for (const auto &elem : s2)
		std::cout << elem;
	std::cout << '\n';
	return 0;
}
