/*
 * Exercise 2.18: Write code to change the value of a pointer. Write code to
 * change the value to which the pointer points.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int a = 5, b = 42;
	int *p = &a;  // p1 points to a
	std::cout << " a = " << a << " b = " << b << std::endl;
	std::cout << " address of a: " << &a << '\n';
	std::cout << " address of b: " << &b << '\n';
	std::cout << "\n value of p: " << p << '\n';
	std::cout << " value to which p1 points to: " << *p << '\n';

	std::cout << "\nchange the value of p. p now points to b\n";
	p = &b;
	std::cout << " value of p: " << p << '\n';
	std::cout << "\nchange the value to which p points to 10\n";
	*p = 10;   
	std::cout << " value to which p points to: " << *p << '\n';
	return 0;
}
