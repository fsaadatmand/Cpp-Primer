/*
 * Exercise 3.40: Write a program to define two character arrays initialized
 * from string literals. Now define a third character array to hold the
 * concatenation of the two arrays. Use strcpy and strcat to copy the two
 * arrays into the third.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <cstring>

int main()
{
	char str1[] = "conca";
	char str2[] = "tenate";
	constexpr auto size = sizeof(str1) + sizeof(str2) + 1;
	char dest[size];
	strcat(strcpy(dest, str1), str2);
	std::cout << dest << '\n';
	return 0;
}
