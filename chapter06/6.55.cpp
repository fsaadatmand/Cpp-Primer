/*
 * Exercise 6.55: Write four functions that add, subtract, multiply, and divide
 * two int values. Store pointers to these functions in your vector from the
 * previous exercise.
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

	return 0;
}
