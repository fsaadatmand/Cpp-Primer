/* 
 * Exercise 10.24: Use bind and check_size to find the first element in a
 * vector of ints that has a value greater than the length of a specified
 * string value.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool check_size(const std::string &s, const std::string::size_type &sz)
{
	return s.size() >= sz;
}

int main()
{
	std::string str{"greater than me!"};
	std::vector<int> ivec{1, 4, 0, 7, 11, 25, 3, 9};
	auto elem = find_if_not(ivec.begin(), ivec.end(),
			bind(
				bind(check_size, std::placeholders::_2, std::placeholders::_1)
				, std::placeholders::_1, str));
	std::cout << *elem << '\n';
	return 0;
}
