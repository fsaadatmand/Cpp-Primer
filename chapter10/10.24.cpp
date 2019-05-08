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

bool check_size(const std::string &s, const std::string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	using std::placeholders::_1; using std::placeholders::_2;
	std::vector<int> ivec{1, 4, 0, 7, 11, 25, 3, 9};
	// using find_if_not, instead of find_if: see note below.
	auto elem = find_if_not(ivec.begin(), ivec.end(),
			bind(check_size, "greater than me!", _1));
	(elem != ivec.end()) ? std::cout << *elem << '\n' 
		                 : std::cout << ("No match found") << '\n';
	// NOTE: inverting the parameters of check_size with bind does not seem to
	// have an effect on the expression inside the function--it is still
	// evaluated as s.size() >= sz. I suspect it has to do with the fact that
	// expression is between s.size (not s) and sz:
	auto invert = bind(check_size, _2, _1);
	std::cout << invert(20, "try me") << '\n';
	return 0;
}
