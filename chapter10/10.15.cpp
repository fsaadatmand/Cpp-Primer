/*
 * Exercise 10.15: Write a lambda that captures an int from its enclosing
 * function and takes an int parameter. The lambda should return the sum of the
 * captured int and the int parameter.
 *
 * by Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int x{5}, y{10};
	auto sum = [y] (const int &x) { return x + y; };
	std::cout << sum(x) << '\n';
	return 0;
}
