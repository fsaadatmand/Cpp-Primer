/*
 * Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	std::vector<int> ivec{10, 35, 83, 19, 67};
	int sum{accumulate(ivec.cbegin(), ivec.cend(), 0)};
	std::cout << sum << '\n';
	return 0;
}
