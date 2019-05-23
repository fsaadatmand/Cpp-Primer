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
#include <utility>

int main()
{
	std::multimap<std::string, std::string> authors{
		{"Plato", "Republic, The"}, {"Plato", "Laws, The"},
		{"Plato", "Symposium, The"}, {"Aristotle", "Politics, The"},
		{"Aristotle", "Ethics, The"}, {"Aristotle", "Rhetoric"},
		{"Augustine", "City of God"},
		{"Hegel", "Phenomenology of Spirit, The"}};

	// Note: if the title is an empty string,
	// then all works by the author will be deleted
	std::pair<const std::string, const std::string> author{"Plato", "Laws, The"};
	auto entries = authors.count(author.first);
	auto iter = authors.find(author.first);
	for (; entries; --entries)
		if (author.second.empty() || iter->second == author.second) {
			iter = authors.erase(iter);
			if (!author.second.empty()) // deleted a specific title
				break;         // we're done; get out
		} else                 // iterate until all works are deleted
			++iter;

	for (const auto &elem : authors)
		std::cout << elem.first << ": " << elem.second << '\n';
	return 0;
}
