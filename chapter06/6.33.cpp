/*
 * Exercise 6.33: Write a recursive function to print the contents of a vector.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

void printVec(std::vector<int>::iterator, std::vector<int>::iterator);

void printVec(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	if (beg == end)
		return;
	std::cout << *beg << " ";
	printVec(beg + 1, end);
}

int main() {
	std::vector<int> v1{50, 23, 63, 99, 32, 74};

	// iterative
	for (auto it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << " ";
	std::cout << '\n';

	// recursive
	printVec(v1.begin(), v1.end());
	std::cout << '\n';

	return 0;
}

