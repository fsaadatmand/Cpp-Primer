/*
 * Exercise 14.42: Using library function objects and adaptors, define an
 * expression to
 *
 * 	(a) Count the number of values that are greater than 1024
 * 	(b) Find the first string that is not equal to pooh
 * 	(c) Multiply all values by 2
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

int main()
{
	// (a)
	std::vector<int> ivec{543, 43421, 485, 19388, 1234};
	decltype(ivec.size()) count = 0;
	const int value = 1024;
	// Using lambda (bonus)
	std::greater<int> isGreater;
	count = std::count_if(ivec.cbegin(), ivec.cend(),
			[&](const int &elem) { return isGreater(elem, value); });
	std::cout << count << '\n';
	// Using bind
	using std::placeholders::_1;
	auto isGreater_Bind = std::bind(std::greater<int>(), _1, value);
	count = std::count_if(ivec.cbegin(), ivec.cend(), isGreater_Bind);
	std::cout << count << '\n';

	// (b)
	std::vector<std::string> svec {"pooh", "pooh", "not pooh", "pooh", "not_pooh"};
	const std::string soughtStr = "pooh";
	decltype(svec.cbegin()) iter;
	// Using lambda (bonus)
	std::not_equal_to<std::string> isNotEqual;
	iter = std::find_if(svec.cbegin(), svec.cend(),
			[&](const std::string &elem) { return isNotEqual(elem, soughtStr); });
	std::cout << *iter << '\n';
	// Using bind
	auto isNotEqual_Bind = std::bind(std::not_equal_to<std::string>(), _1, soughtStr);
	iter = find_if(svec.cbegin(), svec.cend(), isNotEqual_Bind);
	std::cout << *iter << '\n';

	// (c)
	// Using lambda (bonus)
	std::multiplies<int> multiplyBy;
	std::transform(ivec.begin(), ivec.end(), ivec.begin(),
			[&](int &elem) { return multiplyBy(elem, 2); });
	for (const auto &elem : ivec)
		std::cout << ' ' << elem;
	std::cout << '\n';
	// Using bind
	auto timesTwo = std::bind(std::multiplies<int>(), _1, 2);
	std::transform(ivec.begin(), ivec.end(), ivec.begin(), timesTwo);
	for (const auto &elem : ivec)
		std::cout << ' ' << elem;
	std::cout << '\n';
	return 0;
}
