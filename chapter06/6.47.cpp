/*
 * Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.
 * 228) that used recursion to print the contents of a vector to conditionally
 * print information about its execution. For example, you might print the size
 * of the vector on each call. Compile and run the program with debugging
 * turned on and again with it turned off.
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
#ifndef NDEBUG
	std::cout << " size of vector: " << end - beg << " printed element: ";
#endif
	std::cout << *beg << "\n";
	printVec(beg + 1, end);
}

int main() {
	std::vector<int> v1{50, 23, 63, 99, 32, 74};
	printVec(v1.begin(), v1.end());
	return 0;
}
