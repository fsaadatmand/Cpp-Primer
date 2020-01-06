/*
 * Exercise 3.42: Write a program to copy a vector of ints into an array of
 * ints.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	// vector size must be known at compile time
	constexpr size_t size = 10;
	// declare vector
	std::vector<int> ivec(size);
	// define vector
	for (decltype(ivec.size()) i = 0; i < size; ++i)
		ivec[i] = i;
	// copy vector to array
	int a[size];
	for (decltype(ivec.size()) i = 0; i < size; ++i)
		a[i] = ivec[i];
	//print array
	for (const auto &elem : a)
		std::cout << ' ' << elem;
	std::cout << '\n';
	return 0;
}
