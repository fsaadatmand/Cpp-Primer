/*
 * Exercise 14.43: Using library function objects, determine whether a given
 * int value is divisible by any element in a container of ints.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
	using std::placeholders::_1;
	int number = 20;           // int to check against container
	auto hasRemainder = std::bind(std::modulus<int>(), number, _1);
	std::vector<int> ivec{11, 20, 52, 11, 21};
	auto result = find_if_not(ivec.cbegin(), ivec.cend(), hasRemainder);
	std::cout << ((result != ivec.cend()) ? "true" : "false") << '\n';
	return 0;
}
