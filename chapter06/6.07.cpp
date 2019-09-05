/*
 * Exercise 6.7: Write a function that returns 0 when it is first called and
 * then generates numbers in sequence each time it is called again.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int numSqnce()
{
	static int n = 0;
	return n++;
}

int main()
{
	unsigned n = 10;

	for (unsigned i = 0; i <= n; ++i)
		std::cout << numSqnce() << '\n';

	return 0;
}
