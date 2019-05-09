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
	std::list<int> lst{33, 45, 0, 24, 94, 0, 45, 9, 0, 21, 2};
	auto element = find(lst.crbegin(), lst.crend(), 0);
	std::cout << "The last element with the value " << *element++
		      << " is between " << *element-- << " and "
			  << *--element << std::endl;;
	return 0;
}
