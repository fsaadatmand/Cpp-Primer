/*
 * Exercise 3.39: Write a program to compare two strings. Now write a program
 * to compare the values of two C-style character strings.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <cstring>

int main()
{
	// C++ library string 
	std::string string1 = "Hello!";
	std::string string2 = "hello, world!";

	if (string1 < string2)
		std::cout << "string1 < string2\n";
	else if (string1 > string2)
		std::cout << "string1 > string2\n";
	else
		std::cout << "string1 == string2\n";
	// C-Style string
	char str1[] = "Hello!";
	char str2[] = "Hello, world!";
	if (strcmp(str1, str2) < 0)
		std::cout << "str1 < str2\n";
	else if (strcmp(str1, str2) > 0)
		std::cout << "str1 > str2\n";
	else
		std::cout << "str1 == str2\n";
	return 0;
}
