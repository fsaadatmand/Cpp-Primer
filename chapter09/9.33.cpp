/*
 * Exercise 9.33: In the final example in this section what would happen if we
 * did not assign the result of insert to begin? Write a program that omits
 * this assignment to see if your expectation was correct.
 *
 * By Faisal Saadatmand
 *
 * Answer: since we are inserting at points other than the end of a vector, the
 * stored begin value of the iterator will become invalid after the first
 * insertion.
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = {88, 43, 23, 59};
	auto begin = v.begin();
	while (begin != v.end()) {
		++begin;
		v.insert(begin, 42); // begin is invalid
		++begin;
	}

	for (const auto e : v)
		std::cout << e << " ";
	std::cout << '\n';
	return 0;
}
