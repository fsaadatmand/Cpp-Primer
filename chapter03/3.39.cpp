/*
 * Exercise 3.39: Write a program to compare two strings. Now write a program
 * to compare the values of two C-style character strings.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

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

	// C-Style
	char str1[] = "Hello!";
	char str2[] = "Hello, world!";
	char *s, *t;
	int equal = 0;

	for (s = str1, t = str2; *s == *t; s++, t++)
		if (*s == '\0') {
			equal = 1;
			std::cout << "s == t\n";
			break;
		}
	if (!equal) {
		std::cout << ((s - t < 0) ? "s < t\n" : "s > t\n");
	}
	return 0;
}
