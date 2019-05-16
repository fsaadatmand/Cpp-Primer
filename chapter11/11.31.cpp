/*
 * Exercise 11.31: Write a program that defines a multimap of authors and their
 * works. Use find to find an element in the multimap and erase that element.
 * Be sure your program works correctly if the element you look for is not in
 * the map.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
	std::multimap<std::string, std::string> authors{
		{"Plato", "Republic, The"}, {"Plato", "Laws, The"},
		{"Plato", "Symposium, The"}, {"Aristotle", "Politics, The"},
		{"Aristotle", "Ethics, The"}, {"Aristotle", "Rhetoric"},
		{"Augustine", "City of God"},
		{"Hegel", "Phenomenology of Spirit, The"}};

	// if work is an empty string, all works by the author will be deleted
	std::string author("Plato"), work("Laws, The");
	auto entries = authors.count(author);
	auto iter = authors.find(author);
	for (; entries; --entries)
		if (work.empty() || iter->second == work) {
			iter = authors.erase(iter);
			if (!work.empty()) // deleted a specific work
				break;         // we're done; get out
		} else                 // iterate until all works are deleted
			++iter;

	for (const auto &elem : authors)
		std::cout << elem.first << ": " << elem.second << '\n';
	return 0;
}
