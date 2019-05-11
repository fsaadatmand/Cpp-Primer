/*
 * Exercise 11.4: Extend your program to ignore case and punctuation. For
 * example, “example.” “example,” and “Example” should all increment the same
 * counter.
 *
 * By Faisal Saadatmand
 *
 * NOTE: the detection and modification must be made before the word is mapped
 * and indexed.
 *
 */

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

int main()
{
	std::map<std::string, size_t> word_count;
	std::set<std::string> exclude = {"The", "But", "Or", "An", "A",
		                             "the", "but", "or", "an", "a"};
	std::string word;
	while (std::cin >> word) {
		word.front() = std::tolower(word.front());
		if (std::ispunct(word.back()))
			word.pop_back();
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			      << ((w.second > 1) ? " times" : " time") << std::endl;
	return 0;
}
