/*
 * Exercise 12.23: Write a program to concatenate two string literals, putting
 * the result in a dynamically allocated array of char. Write a program to
 * concatenate two library strings that have the same value as the literals
 * used in the first program.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <string>
#include <cstring>

int main()
{
	// string literals
	const char *s1 = "conca";
	const char *s2 = "tnate";
	size_t size = strlen(s1) + strlen(s2);
	char *ps = new char[size + 1];    // add 1 for '\0'
	std::strcpy(ps, s1);
	std::strcat(ps, s2);
	auto ch = ps;
	while (*ch)  // *p != '\0'
		std::cout << *ch++;
	std::cout << '\n';
	delete [] ps;

	// library strings
	auto lstring = std::string("conca") + std::string("tnate");
	std::cout << lstring << std::endl;
	return 0;
}
