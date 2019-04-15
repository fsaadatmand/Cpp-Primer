/*
 * Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to
 * use references instead of pointers to swap the value of two ints. Which
 * version do you think would be easier to use and why?
 * 
 * Answer: the "pass by reference" s easier use because it simplifies the
 * function call syntax. No need to worry about the pointers or the address of
 * operator.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void swap(int &, int &);

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x = 3, y = 5;

	std::cout << "BEFORE calling swap():\t"
		       << "x = " << x << '\t'
		       << "y = " << y << '\n';
	swap(x, y);
	std::cout << "AFTER calling swap():\t"
		       << "x = " << x << '\t'
		       << "y = " << y << '\n';

	return 0;
}
