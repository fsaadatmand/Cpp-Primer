/*
 * Exercise 16.41: Write a version of sum with a return type that is guaranteed
 * to be large enough to hold the result of the addition.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <type_traits>
#include <limits>

template <typename T1, typename T2>
auto sum(T1 lhs, T2 rhs) -> decltype(lhs + rhs)
{
	return lhs + rhs;
}

int main()
{
	auto sumOfTwo_1 = sum(45923.7, 589);
	std::cout << sumOfTwo_1 << '\n';

	// Note: the variable sumOfTwo will overflow, but the code is legal.
	auto sumOfTwo_2 = sum(std::numeric_limits<long long unsigned>::max(),
			std::numeric_limits<long long unsigned>::max());
	std::cout << sumOfTwo_2 << '\n';
	return 0;
}
