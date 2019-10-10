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
	std::vector<int> ivec{11, 20, 52, 11, 21};
	const int number = 20;

	// Using lambda
	auto mod = std::modulus<int>();
	auto result1 = std::any_of(ivec.cbegin(), ivec.cend(),
			[&](const int &elem) { return !mod(number, elem); });
	std::cout << (result1 ? "true" : "false") << '\n';

	// Using bind
	using std::placeholders::_1;
	auto hasRemainder = std::bind(std::modulus<int>(), number, _1);
	auto result2 = find_if_not(ivec.cbegin(), ivec.cend(), hasRemainder);
	std::cout << ((result2 != ivec.cend()) ? "true" : "false") << '\n';

	return 0;
}
