/*
 * Exercise 3.35: Using pointers, write a program to set the elements in an
 * array to zero.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	constexpr size_t size = 10;
	int a[size];
	for (int *p = a; p < a + size ; ++p)
		*p = 0;
	for (const auto &elem : a)
		std::cout << ' ' << elem;
	std::cout << '\n';
	return 0;
}
