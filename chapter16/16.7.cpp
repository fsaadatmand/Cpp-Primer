/*
 * Exercise 16.7: Write a constexpr template that returns the size of a given
 * array.
 *
 * By Faisal Saadatmand
 */

template <typename T, unsigned N>
constexpr unsigned array_size(T (&arr)[N])
{
	return N;
}

#include <iostream>
#include <string>

int main()
{
	int a[10];
	double d[7];
	char e[18];
	std::cout << array_size(a) << '\n';
	std::cout << array_size(d) << '\n';
	std::cout << array_size(e) << '\n';
	return 0;
}
