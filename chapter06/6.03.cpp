/*
 * Exercise 6.3: Write and test your own version of fact.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int fact(int val)
{
	int factorial = 1;
	while (val > 1)
		factorial *= val--;
	return factorial;
}

int main()
{
	for (int i = 0; i < 10; ++i) 
		std::cout << i << "! = " << fact(i) << '\n';
	return 0;
}
