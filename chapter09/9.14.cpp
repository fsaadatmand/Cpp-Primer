/*
 * Exercise 9.14: Write a program to assign the elements from a list of char*
 * pointers to C-style character strings to a vector of strings.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()
{
	std::list<const char *> cslist;
	cslist.assign({"C-style", "char", "string"}); /* initializer list */

	std::vector<std::string> svec;
	svec.assign(cslist.cbegin(), cslist.cend()); 

	for (const auto &elem : svec)
		std::cout << elem << '\n';
	return 0;
}
