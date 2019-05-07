/*
 * Exercise 10.6: Using fill_n, write a program to set a sequence of int values
 * to 0.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec(10, 1);
	for (const auto & elem: ivec)
		std::cout << elem << ' ';
	std::cout << '\n';
	fill_n(ivec.begin(), 10, 0);
	for (const auto & elem: ivec)
		std::cout << elem << ' ';
	std::cout << '\n';
	return 0;
}
