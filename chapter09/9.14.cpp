/*
 * Exercise 9.14: Write a program to assign the elements from a list of char*
 * pointers to C-style character strings to a vector of strings.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
	std::list<const char *> cStr;
	std::vector<std::string> svec;

	char a0[30] = "a list of char * poniters to";
	char a1[8] = {'C', '-', 'S', 't', 'y', 'l', 'e', '\0'};
	char a2[] = "charater strings";
	cStr.push_back(a0);
	cStr.push_back(a1);
	cStr.push_back(a2);
	cStr.push_back("to vector of strings");

	svec.assign(cStr.cbegin(), cStr.cend()); 

	for (const auto elements : svec)
		std::cout << elements << '\n';
	return 0;
}
