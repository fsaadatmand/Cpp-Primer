/*
 * Exercise 4.11: Write an expression that tests four values, a, b, c, and d,
 * and ensures that a is greater than b, which is greater than c, which is
 * greater than d.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int a{30} , b{9}, c{5}, d{-1};
	if (a > b && b > c && c > d)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0;
}
