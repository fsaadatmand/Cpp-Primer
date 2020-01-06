/*
 * Exercise 3.42: Write a program to copy a vector of ints into an array of
 * ints.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const auto size = ivec.size(); // not a constexpr
	int a[size]; // variable length array
	for (decltype(ivec.size()) i = 0; i < size; ++i)
		a[i] = ivec[i];
	for (const auto &elem : a)
		std::cout << ' ' << elem;
	std::cout << '\n';
	return 0;
}
