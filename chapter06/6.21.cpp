/*
 * Exercise 6.21: Write a function that takes an int and a pointer to an int
 * and returns the larger of the int value or the value to which the pointer
 * points. What type should you use for the pointer?
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int max(const int i, const int *p)
{
	return (!p || i > *p) ? i : *p;
}

int main()
{
	int x = 20, y = 42;
	std::cout << max(x, &y) << '\n';
	return 0;
}
