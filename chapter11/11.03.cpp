/*
 * Exercise 11.3: Write your own version of the word-counting program.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <map>
#include <set>

int main()
{
	std::map<std::string, size_t> word_count;
	std::set<std::string> exclude = {"The", "But", "Or", "An", "A",
		                             "the", "but", "or", "an", "a"};
	std::string word;
	while (std::cin >> word)
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
				  << ((w.second > 1) ? " times" : " time") << std::endl;
	return 0;
}
