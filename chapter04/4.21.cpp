/*
 * Exercise 4.21: Write a program to use a conditional operator to find the
 * elements in a vector<int> that have odd value and double the value of each
 * such element.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (auto &element : vec)
		std::cout << (!(element % 2) ? element * 2 : element) << " ";
	std::cout << '\n';

	return 0;
}
