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
	using std::placeholders::_1;
	// (a)
	std::vector<int> ivec{543, 43421, 485, 19388, 1234};
	auto intGreater = std::bind(std::greater<int>(), _1, 1024);
	auto vc = std::count_if(ivec.cbegin(), ivec.cend(), intGreater);
	std::cout << vc << '\n';
	// (b)
	std::vector<std::string> svec {"pooh", "pooh", "not pooh", "pooh", "not_pooh"};
	auto strNotEqual = std::bind(std::not_equal_to<std::string>(), _1, "pooh");
	auto pooh = find_if(svec.cbegin(), svec.cend(), strNotEqual);
	std::cout << *pooh << '\n';
	// (c)
	
	auto timesTwo = std::bind(std::multiplies<int>(), _1, 2);
	for (auto &elem : ivec)
		elem = timesTwo(elem);
//	std::replace_if(ivec.begin(), ivec.end(), [](int i) { return i > 0;}, timesTwo);
	for (const auto &elem : ivec)
		std::cout << elem << ' ';
	std::cout << '\n';
	return 0;
}
