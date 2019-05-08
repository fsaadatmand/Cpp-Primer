/*
 * Exercise 10.22: Rewrite the program to count words of size 6 or less using
 * functions in place of the lambdas.
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
	return s.size() <= sz;
}

int main()
{
	using std::placeholders::_1;
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle",
								   "sixteen", "times"};
	const std::string::size_type size{6};
	auto count = count_if(words.begin(), words.end(),
			bind(check_size, _1, size));
	std::cout << count << " words are greater than " << size << '\n';
	return 0;
}
