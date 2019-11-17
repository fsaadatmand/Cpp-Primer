/*
 * Exercise 6.5: Write a function to return the absolute value of its argument.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <limits>

int absolute(int n)
{
	if (n < 0)
		n = -n; // will overflow the largest negative
	return n;
}

int main()
{
	std::cout << absolute(-5) << '\n';
	// largest negative int--will overflow.
	std::cout << absolute(std::numeric_limits<int>::min()) << '\n';
	// second largest negative int--ok
	std::cout << abs(std::numeric_limits<int>::min() + 1) << '\n';
	return 0;
}
