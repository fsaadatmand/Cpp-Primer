/*
 * Exercise 6.56: Call each element in the vector and print their result.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <stdexcept>
#include <vector>

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

int main() {
	int f(int, int);
	using fptr = decltype(f) *;
	std::vector<fptr> functions{ add, substract, multiply, divide };
	for (const auto &elem : functions)
		try {
			std::cout << elem(15, 5) << '\n';
		} catch (std::runtime_error err) {
			std::cout << err.what() << '\n';
		}
	return 0;
}
