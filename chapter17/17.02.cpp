/*
 * Exercise 17.2: Define a tuple that holds a string, a vector<string>, and a
 * pair<string, int>.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main()
{
	std::tuple<std::string, std::vector<std::string>,
		std::pair<std::string, int>>
		tpData{"string",
			  {"vector", "of", "strings"}, 
			  {"pair of string and int", 2}};

	std::cout << std::get<0>(tpData) << '\n';
	for (const auto &elm : std::get<1>(tpData))
		std::cout << elm << ' ';
	std::cout << '\n';
	std::cout << std::get<2>(tpData).first << ' '
			  << std::get<2>(tpData).second << '\n';
	return 0;
}
