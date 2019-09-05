/*
 * Exercise 6.3: Write and test your own version of fact.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int fact(int val)
{
	int result = 1;
	while (val > 1)
		result *= val--;
	return result;
}

int main()
{
	int x = 5; 
	std::cout << x << "! is " << fact(x) << '\n';
	return 0;
}
