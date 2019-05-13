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

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cctype>

int main()
{
	std::map<std::string, size_t> word_count;
	std::set<std::string> exclude = {"the", "but", "or", "an", "a"};
	std::string word;
	while (std::cin >> word) {
		for (auto &c : word) { c = tolower(c); } // ignore case
		// Note: I do not skip punctuation marks in the middle of the word
		// because they could be ambiguous and require interpretation as to
		// whether they were intended or now.
		if (ispunct(word.front()))  // skip punctuation mark at the beginning
			word.erase(0, 1);
		if (ispunct(word.back()))   // skip punctuation mark at the end
			word.pop_back();
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			      << ((w.second > 1) ? " times" : " time") << std::endl;
	return 0;
}
