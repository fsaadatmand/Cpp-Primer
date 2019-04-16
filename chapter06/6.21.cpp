/*
 * Exercise 6.21: Write a function that takes an int and a pointer to an int
 * and returns the larger of the int value or the value to which the pointer
 * points. What type should you use for the pointer?
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int compareInt(const int, const int *);

int compareInt(const int i, const int *j)
{
	return (!j || i > *j) ? i : *j;
}

int main()
{
	int x;
	const int y = 42;
	
	std::cout << compareInt(x, &y) << '\n';

	return 0;
}
