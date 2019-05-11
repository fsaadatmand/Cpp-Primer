/*
 * Exercise 11.7: Define a map for which the key is the family’s last name and
 * the value is a vector of the children’s names. Write code to add new
 * families and to add new children to an existing family.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
	std::map<std::string, std::vector<std::string>>
		families{{"Smith", {"John", "Jane"}}, {"Adam", {"Kane", "Abel"}}};
	std::string familyName("Marley");
	std::vector<std::string> children{"Ziggy", "Cedella", "Damian"};

	families[familyName] = children;            // add new family and children
	families["Smith"].push_back("Kevin");       // add child to existing family

	for (const auto &fmly : families) {         // print map
		std::cout << fmly.first << ": ";
		for (const auto &chldn : fmly.second)
			std::cout << chldn << " ";
		std::cout << '\n';
	}
	return 0;
}
