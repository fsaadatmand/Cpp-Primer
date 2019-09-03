/*
 * Exercise 10.1: The algorithm header defines a function named count that,
 * like find, takes a pair of iterators and a value. count returns a count of
 * how often that value appears. Read a sequence of ints into a vector and
 * print the count of how many elements have a given value.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> ivec;
	constexpr int value{5};
	int number;
	while (std::cin >> number)
		ivec.push_back(number);
	std::cout << count(ivec.cbegin(), ivec.cend(), value) 
		      << " elements have the value " << value << '\n';
	return 0;
}
