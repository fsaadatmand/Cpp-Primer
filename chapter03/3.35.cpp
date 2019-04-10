/*
 * Exercise 3.35: Using pointers, write a program to set the elements in an
 * array to zero.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int a[10];

	for (int *p = a, *e = std::end(a)
			; p < e ; ++p)
		*p = 0;

	for (auto element : a)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
