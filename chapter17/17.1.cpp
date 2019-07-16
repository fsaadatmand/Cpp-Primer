/*
 * Exercise 17.1: Define a tuple that holds three int values and initialize the
 * members to 10, 20, and 30.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <tuple>

int main()
{
	std::tuple<int, int, int> integers{10, 20, 30};
	std::cout << std::get<0>(integers) << '\n'
			  << std::get<1>(integers) << '\n'
			  << std::get<2>(integers) << '\n';
	return 0;
}
