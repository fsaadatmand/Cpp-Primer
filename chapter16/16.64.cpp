/*
 * Exercise 16.64: Write a specialized version of the template from the
 * previous exercise to handle vector<const char*> and a program that uses this
 * specialization.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::size_t v_count(const std::vector<T> &vec, const T &n)
{
	// forwarding is not necessary since v_count doesn't change the value of n.
	return std::count(vec.cbegin(), vec.cend(), n);
}

template <>
std::size_t v_count(const std::vector<const char *> &vec, const char* const &n)
{
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

	// uses specialized const char * version
	const char *p = "one";
	std::vector<const char *> CharPvec{"one", "two", "three", "four", "five"};
	std::cout << v_count(CharPvec, p) << '\n';
	return 0;
}
