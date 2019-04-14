/*
 * Exercise 5.17: Given two vectors of ints, write a program to determine
 * whether one vector is a prefix of the other. For vectors of unequal length,
 * compare the number of elements of the smaller vector. For example, given the
 * vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your
 * program should return true.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1{0, 1, 1};
	std::vector<int> v2{0, 1, 1, 2, 3, 5, 8};
	
	if (v1.size() == v2.size()) {
		std::cerr << "equal size vectors\n";
		return -1;
	}

	auto it1 = v1.begin();
	auto it2 = v2.begin();
	while (it1 != v1.end() && it2 != v2.end() && *it1 == *it2) {
		it1++;
		it2++;
	}

	if (it1 == v1.end())
		std::cout << "true\n";
	else
		std::cout << "false\n";

	return 0;
}
