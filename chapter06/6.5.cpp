/*
 * Exercise 6.5: Write a function to return the absolute value of its argument.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int absolute(int n)
{
	if (n < 0)
		n = -n;
	return n;
}
int main()
{
	int x = -5;
	
	std::cout << "absolute value of " << x 
		      << " is " << absolute(x) << '\n';

	return 0;
}
