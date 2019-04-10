
/*
 * Exercise 3.41: Write a program to initialize a vector from an array of ints.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> ivec(std::begin(a), std::end(a));

	for (auto element : ivec)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
