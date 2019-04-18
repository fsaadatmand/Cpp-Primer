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

	// for range: this is the simplest way. The rest is for academic purposes.
	for (auto element : vfPointers)
		std::cout << element(15, 3) << '\n';

	// for loop: iterator
	for (auto it = vfPointers.begin(); it < vfPointers.end(); ++it)
		std::cout << (*it)(15, 3) << '\n';

	// for loop: subscripts
	for (decltype(vfPointers.size()) i = 0; i < vfPointers.size(); ++i)
		std::cout << vfPointers[i](15, 3) << '\n';

	// while loop: raw pointers
	constexpr unsigned vsize = 4;
	std::vector<fp> *vfpp = &vfPointers;
	std::vector<fp> *vfppEnd = vfpp + vsize;
	auto *dataP = vfPointers.data();

	while (vfpp++ != vfppEnd)
		std::cout << (*dataP++)(15, 3) << '\n' ;

	return 0;
}
