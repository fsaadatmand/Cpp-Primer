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
	using fp = decltype(add) *;
	std::vector<fp> vfPointers;
	vfPointers.push_back(add);
	vfPointers.push_back(substract);
	vfPointers.push_back(multiply);
	vfPointers.push_back(divide);
	for (const auto &elem : vfPointers)
		try {
			std::cout << elem(15, 5) << '\n';
		} catch (std::runtime_error err) {
			std::cout << err.what() << '\n';
		}
	return 0;
}
