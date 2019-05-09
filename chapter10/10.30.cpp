/*
 * Exercise 10.30: Use stream iterators, sort, and copy to read a sequence of
 * integers from the standard input, sort them, and then write them back to the
 * standard output.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::istream_iterator<int> in_iter(std::cin), eof;
	std::ostream_iterator<int> out_iter(std::cout, " ");
	std::vector<int> buffer(in_iter, eof);
	sort(buffer.begin(), buffer.end());
	copy(buffer.cbegin(), buffer.cend(), out_iter);
	std::cout << std::endl;
	return 0;
}
