/*
 * Exercise 10.36: Use find to find the last element in a list of ints with
 * value 0.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iterator>
#include <iostream>
#include <list>

int main()
{
	std::list<int> ints{33, 45, 0, 24, 94, 0, 45, 9, 0, 21, 2};
	constexpr int sought_value = 0;
	auto element = std::find(ints.crbegin(), ints.crend(), sought_value);
	if (element != ints.crend()) {
		std::cout << *element << '\n';
		while (element != ints.crend())
			std::cout << ' ' << *element--;
		std::cout << '\n';
	}
	return 0;

}
