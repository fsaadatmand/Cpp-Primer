/*
 * Exercise 11.14: Extend the map of children to their family name that you
 * wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a
 * pair that holds a child’s name and birthday.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

int main()
{
	std::map<std::string, std::vector<std::pair<std::string, std::string>>>
		families{{"Smith", {{"John", "July 3, 1900"}, {"Jane", "Jan 23, 1898"}}},
			     {"Adam", {{"Cane", "7000bc"}, {"Abel", "7001bc"}}}};
	std::string familyName("Marley");
	std::vector<std::pair<std::string,std::string>>
		children{{"Ziggy", "Oct 17, 1968"},
			    {"Cedella", "Aug 23, 1967"},
				{"Damian", "Jul 21, 1978"}};

	families[familyName] = children;            // add new family and children
	families["Smith"].push_back({"Kevin", "Aug 2, 1970"});       // add child to existing family

	for (const auto &fmly : families) {         // print map
		std::cout << fmly.first << ":\n";
		for (const auto &child : fmly.second)
			std::cout << child.first << " " << child.second << "\n";
		std::cout << '\n';
	}
	return 0;
}
