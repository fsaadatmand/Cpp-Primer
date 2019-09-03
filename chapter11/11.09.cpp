/*
 * Exercise 11.9: Define a map that associates words with a list of line
 * numbers on which the word might occur.
 *
 * By Faisal Saadatmand
 *
 * NOTE: I am not sure if this is the correct answer, as ii does not use any of
 * the techniques mentioned in this section. I'll revisit it once I gave it
 * a little more thought.
 *
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

std::set<std::string> getwords(const std::string &ln)
{
	std::set<std::string> words_set;
	auto start = ln.cbegin(), end = ln.cend();
	while (start != ln.cend()) {
		start = find_if(start, ln.cend(),
				[](const char &c) { return isalpha(c); });
		end = find_if(start, ln.cend(),
				[](const char &c) { return !isalpha(c); });
		if (start != end)
			words_set.insert(std::string(start, end));
		start = end; 
	}
	return words_set;
}

int main()
{
	std::map<std::string, std::list<unsigned>> word_position;
	std::string line;
	std::set<std::string> words;
	
	for (unsigned lineNumber = 1; getline(std::cin, line); ++lineNumber) {
		words = getwords(line);
		for (const auto word : words)
			word_position[word].push_back(lineNumber);
	}
	for (const auto &w : word_position) {
		std::cout << w.first << ": ";
		for (const auto &ln : w.second)
			std::cout << ln << ' ';
		std::cout << '\n';
	}
	return 0;
}
