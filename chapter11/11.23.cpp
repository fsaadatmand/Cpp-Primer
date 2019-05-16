/*
 * Exercise 11.23: Rewrite the map that stored vectors of children’s names with
 * a key that is the family last name for the exercises in § 11.2.1 (p. 424) to
 * use a multimap.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
	std::multimap<std::string, std::vector<std::string>>
		families{{"Smith", {"John", "Jane"}}, {"Adam", {"Cane", "Abel"}}};
	std::string familyName("Marley");
	std::vector<std::string> children{"Ziggy", "Cedella", "Damian"};
	//	since we are using a multimap we must use
	//	the insert operation instead of subscripts
	families.insert({familyName, children});
	// this will add another key "Smith"
	// with the value "Kevin" to the families
	families.insert({"Smith", {"Kevin"}});
	// print multimap
	for (const auto &fmly : families) {
		std::cout << fmly.first << ": ";
		for (const auto &chldn : fmly.second)
			std::cout << chldn << " ";
		std::cout << '\n';
	}
	return 0;
}
