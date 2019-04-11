/*
 * Exercise 3.35: Using pointers, write a program to set the elements in an
 * array to zero.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	constexpr int size = 10;
	int a[size];

	for (int *p = a; p < a + size ; ++p)
		*p = 0;

	for (auto element : a)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
