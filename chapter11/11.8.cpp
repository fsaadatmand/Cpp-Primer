/*
 * Exercise 11.8: Write a program that stores the excluded words in a vector
 * instead of in a set. What are the advantages to using a set?
 *
 * By Faisal Saadatmand
 *
 * Answer: aside from the fact that a vector does not have a find operation--an
 * algorithm function must be used--it seems that there are no obvious
 * advantages in using set over a vector. In most case that is true. However,
 * when dealing with a large set of data, at least in theory, the
 * implementation of a set is faster for data access, given that it uses keys
 * and a binary search algorithm to locate elements in a list.
 *
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;
	std::vector<std::string> exclude{"the", "but", "and", "or", "an", "a"};
	while (std::cin >> word) {
		word.front() = tolower(word.front());
		if (ispunct(word.back()))
			word.pop_back();
		if (find(exclude.cbegin(), exclude.cend(), word) == exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count)
		std:: cout << w.first << " occurs " << w.second
			       << ((w.second > 1) ? " times" : " time") << '\n';
	return 0;
}
