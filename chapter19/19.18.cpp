/*
 * Exercise 19.18: Write a function that uses count_if to count how many empty
 * strings there are in a given vector.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> svec{"one", "", "three", "", "", "five", "six"};
	auto f = std::mem_fn(&std::string::empty);
	auto count = std::count_if(svec.begin(), svec.end(), f);
	std::cout << count << '\n';
	return 0;
}
