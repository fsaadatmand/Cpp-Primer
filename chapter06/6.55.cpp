/*
 * Exercise 6.55: Write four functions that add, subtract, multiply, and divide
 * two int values. Store pointers to these functions in your vector from the
 * previous exercise.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <stdexcept>
#include <vector>

int f(int, int);

int add(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	if (!b)
		throw std::runtime_error("zero divisor");
	return a / b;
}

int main()
{
	using fptr = decltype(f) *;
	std::vector<fptr> functions{ add, substract, multiply, divide };
	return 0;
}
