/*
 * Exercise 2.18: Write code to change the value of a pointer. Write code to
 * change the value to which the pointer points.
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int a = 0, b = 0;

	int *p1 = &a;  // p1 points to a
	int *p2 = &b;  // p2 points to b

	p1 = p2;       // change the value of p1. p1 points to b
	*p1 = 10;      // change the value to which p1 points. b = 10

	std::cout << "a = " << a << " b =  " << b << std::endl;
	std::cout << "address of p1: " << p1 << std::endl;
	std::cout << "address of p2: " << p2 << std::endl;
	std::cout << "value to which of p1 (b): " << *p1 << std::endl;
	std::cout << "value to which of p2 (b): " << *p2 << std::endl;

	return 0;
}
