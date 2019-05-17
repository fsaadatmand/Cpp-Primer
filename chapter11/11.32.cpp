/*
 * Exercise 11.32: Using the multimap from the previous exercise, write a
 * program to print the list of authors and their works alphabetically.
 *
 * By Faisal Saadatmand
 * 
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <utility>

bool compareValues(std::pair<const std::string, const std::string> lhs,
		           std::pair<const std::string, const std::string> rhs)
{
	return lhs.second < rhs.second;
}

int main()
{
	std::multimap<std::string, std::string> authors{
		{"Plato", "Republic, The"}, {"Plato", "Laws, The"},
		{"Plato", "Symposium, The"}, {"Aristotle", "Politics, The"},
		{"Aristotle", "Ethics, The"}, {"Aristotle", "Rhetoric"},
		{"Augustine", "City of God, The"},
		{"Hegel", "Phenomenology of Spirit, The"}};
	
	auto map_it = authors.begin();
	while (map_it != authors.end()) {
		auto  entries = authors.count(map_it->first);
		if (entries > 1) {
			auto pos = authors.equal_range(map_it->first);
			std::multiset<std::pair<std::string, std::string>,
				decltype(compareValues) *>
					titles(pos.first, pos.second, compareValues);
			for (const auto &t : titles) {
				std::cout << t.first << ": " << t.second << '\n';
				++map_it;
			}
		} else {
			std::cout << map_it->first << ": " << map_it->second << '\n';
			++map_it;
		}
	}
	return 0;
}
