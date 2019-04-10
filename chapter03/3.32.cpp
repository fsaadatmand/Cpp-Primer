/*
 * Exercise 3.32: Copy the array you defined in the previous exercise into
 * another array. Rewrite your program to use vectors.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	const unsigned size = 10;
	int a1[size];
	int a2[size];
	std::vector<int> ivec1;
	std::vector<int> ivec2;

	for (size_t i = 0; i < size; ++i)  // define array
		a1[i] = i;
	for (size_t i = 0; i < size; ++i)  // copy array
		a2[i] = a1[i];

	
	for (decltype(ivec1.size()) ix = 0; ix < size; ++ix)  // define vector
		ivec1.push_back(ix);
	ivec2 = ivec1;                     // copy vector

	std::cout << "a1: ";               // print a1
	for (auto element : a1)
		std::cout << element << " ";
	std::cout << '\n';

	std::cout << "a2: ";               // print a2
	for (auto element : a2)
		std::cout << element << " ";
	std::cout << '\n';

	std::cout << "ivec1: ";            // print ivec1
	for (auto element : ivec1)
		std::cout << element << " ";
	std::cout << '\n';

	std::cout << "ivec2: ";            // print ivec2
	for (auto element : ivec2)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
