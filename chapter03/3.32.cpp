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
	// copy array
	const size_t size = 10;
	int a1[size];
	for (size_t i = 0; i < size; ++i)  // define array
		a1[i] = i;
	int a2[size];
	for (size_t i = 0; i < size; ++i)  // copy array
		a2[i] = a1[i];
	// print arrays
	std::cout << "a1:";
	for (auto elem : a1)
		std::cout << ' ' << elem;
	std::cout << '\n';
	std::cout << "a2:";
	for (auto elem : a2)
		std::cout << ' ' << elem;
	std::cout << '\n';

	// copy vector
	std::vector<int> ivec1;
	for (decltype(ivec1.size()) ix = 0; ix < size; ++ix)  // define vector
		ivec1.push_back(ix);
	std::vector<int> ivec2(ivec1); // copy vector
	// print vectors
	std::cout << "ivec1:";
	for (auto elem : ivec1)
		std::cout << ' ' << elem;
	std::cout << '\n';
	std::cout << "ivec2:";
	for (auto elem : ivec2)
		std::cout << ' ' << elem;
	std::cout << '\n';

	return 0;
}
