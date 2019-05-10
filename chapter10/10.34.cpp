/*
 * Exercise 10.34: Use reverse_iterators to print a vector in reverse order.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8 , 9};
	std::ostream_iterator<int> out_iter(std::cout, " ");
	copy(ivec.crbegin(), ivec.crend(), out_iter);
	std::cout << std::endl;
	return 0;
}
