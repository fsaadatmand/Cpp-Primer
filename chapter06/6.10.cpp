/*
 * Exercise 6.10: Using pointers, write a function to swap the values of two
 * ints. Test the function by calling it and printing the swapped values.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void swap(int *, int *);

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 3, y = 5;

	std::cout << "BEFORE calling swap():\t"
		       << "x = " << x << '\t'
		       << "y = " << y << '\n';
	swap(&x, &y);
	std::cout << "AFTER calling swap():\t"
		       << "x = " << x << '\t'
		       << "y = " << y << '\n';

	return 0;
}
