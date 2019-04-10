/*
 * Exercise 3.31: Write a program to define an array of ten ints. Give each
 * element the same value as its position in the array.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	const unsigned size = 10;
	int a[size];

	for (size_t i = 0; i < size; ++i)
		a[i] = i;
	for (auto element : a)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
