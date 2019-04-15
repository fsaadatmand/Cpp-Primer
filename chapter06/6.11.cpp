/*
 * Exercise 6.11: Write and test your own version of reset that takes a
 * reference.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void rest(int &i)
{
	i = 0;
}

int main()
{
	int x = 10;
	
	std::cout << x << '\n';
	rest(x);
	std::cout << x << '\n';

	return 0;
}
