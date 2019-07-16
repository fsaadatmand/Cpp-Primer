/*
 * Exercise 16.63: Define a function template to count the number of
 * occurrences of a given value in a vector. Test your program by passing it a
 * vector of doubles, a vector of ints, and a vector of strings.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::size_t v_count(const std::vector<T>& vec, const T &n)
{
	// forwarding is not necessary since v_count doesn't change the value of n.
	return std::count(vec.cbegin(), vec.cend(), n);
}

int main() {
	std::vector<int> ivec{7, 12, 94, 7, 12, 48, 7};
	std::cout << v_count(ivec, 7) << '\n';

	std::vector<double> dvec{7.3, 12, 94, 7.3, 12, 48, 7.3};
	std::cout << v_count(dvec, 7.3) << '\n';

	std::vector<std::string>
		svec{"three", "one", "ten", "three", "six", "two", "three"};
	std::cout << v_count(svec, std::string("three")) << '\n';
	return 0;
}
