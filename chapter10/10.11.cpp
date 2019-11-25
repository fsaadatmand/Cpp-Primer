/*
 * Exercise 10.11: Write a program that uses stable_sort and isShorter to sort
 * a vector passed to your version of elimDups. Print the vector to verify that
 * your program is correct.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> &elimDups(std::vector<std::string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return words;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle"};
	elimDups(words); // sort (unique words) alphabetically
	// sort by size length, but maintain alphabetical sort
	stable_sort(words.begin(), words.end(), isShorter);
	for(const auto &word : words)
		std::cout << ' ' << word;
	std::cout << '\n';
	return 0;
}
