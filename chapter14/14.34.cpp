/*
 * Exercise 14.34: Define a function-object class to perform an if-then-else
 * operation: The call operator for this class should take three parameters. It
 * should test its first parameter and if that test succeeds, it should return
 * its second parameter; otherwise, it should return its third parameter.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

struct if_then_else {
	int operator()(const int x, const int y, const  int z)
		{ return (x > 0) ? y : z; }
};

int main()
{
	int a = -4, b = 8, c = 10;
	if_then_else check;
	std::cout << check(a, b, c) << '\n';
	return 0;
}
