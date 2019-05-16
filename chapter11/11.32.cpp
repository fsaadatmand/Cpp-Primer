/*
 * Exercise 11.32: Using the multimap from the previous exercise, write a
 * program to print the list of authors and their works alphabetically.
 *
 * By Faisal Saadatmand
 * 
 * TODO: find a simple way yo sort the titles as well.
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

int main()
{
	std::multimap<std::string, std::string> authors{
		{"Plato", "Republic, The"}, {"Plato", "Laws, The"},
		{"Plato", "Symposium, The"}, {"Aristotle", "Politics, The"},
		{"Aristotle", "Ethics, The"}, {"Aristotle", "Rhetoric"},
		{"Augustine", "City of God, The"},
		{"Hegel", "Phenomenology of Spirit, The"}};

	for (const auto &author : authors) 
		std::cout << author.first << ": "
			      << author.second << '\n';
	return 0;
}
