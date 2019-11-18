/*
 * Exercise 6.33: Write a recursive function to print the contents of a vector.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

void printVec(std::vector<int>::const_iterator beg,
				std::vector<int>::const_iterator end)
{
	if (beg == end)
		return;
	std::cout << " " << *beg;
	printVec(beg + 1, end);
}

int main() {
	std::vector<int> v1{50, 23, 63, 99, 32, 74};
	printVec(v1.cbegin(), v1.cend());
	std::cout << '\n';
	return 0;
}
