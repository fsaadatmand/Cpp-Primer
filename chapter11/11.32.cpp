/*
 * Exercise 11.32: Using the multimap from the previous exercise, write a
 * program to print the list of authors and their works alphabetically.
 *
 * By Faisal Saadatmand
 * 
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
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
		// count entries per author
		auto entries = authors.count(map_it->first);
		if (entries > 1) { // authors with more than one title
			// get the range for the author's titles
			auto pos = authors.equal_range(map_it->first);
			// define and initialize a multiset of pairs of strings
			// from that range, and use a comparator to sort by values
			// rather than by keys
			std::multiset<std::pair<std::string, std::string>,
				decltype(compareValues) *>
					titles(pos.first, pos.second, compareValues);
			// print the sorted range and increment the map iterator
			for (const auto &t : titles) {
				std::cout << t.first << ": " << t.second << '\n';
				++map_it;
			}
		} else { // authors with only a single title
			std::cout << map_it->first << ": " << map_it->second << '\n';
			++map_it;
		}
	}
	return 0;
}
