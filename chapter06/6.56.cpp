/*
 * Exercise 6.56: Call each element in the vector and print their result.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int add(int, int);
int substract(int, int);
int multiply(int, int);
int divide(int, int);

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
	if (!b) {
		std::cerr << "zero divisor\n";
		return -1;
	}
	return a / b;
}

int main() {
	typedef decltype(add) *fp;

	fp addP = add, substractP = substract,
	   multiplyP = multiply, divideP = divide;

	std::vector<fp> vfPointers;
	vfPointers.push_back(addP);
	vfPointers.push_back(substractP);
	vfPointers.push_back(multiplyP);
	vfPointers.push_back(divideP);

	for (auto element : vfPointers)
		std::cout << element(15, 3) << '\n';
	return 0;
}
