/*
 * Exercise 10.14: Write a lambda that takes two ints and returns their sum.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	auto sum = [] (const int &a, const int &b) { return a + b; };
	int x{5}, y{10};
	std::cout << sum(x, y) << '\n';
	return 0;
}
