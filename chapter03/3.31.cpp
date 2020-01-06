/*
 * Exercise 3.31: Write a program to define an array of ten ints. Give each
 * element the same value as its position in the array.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	const size_t size = 10;
	int a[size];

	for (size_t i = 0; i < size; ++i)
		a[i] = i;
	for (const auto &elem : a)
		std::cout << ' ' << elem;
	std::cout << '\n';
	return 0;
}
