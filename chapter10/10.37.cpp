/*
 * Exercise 10.37: Given a vector that has ten elements, copy the elements from
 * positions 3 through 7 in reverse order to a list.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto from = ivec.crend() - 8;     // position 7
	auto to = ivec.crend() - 3;       // position 3
	std::list<int> lst(from, to);
	for (auto &element : lst)
		std::cout << element << ' ';
	std::cout << std::endl;
	return 0;
}
