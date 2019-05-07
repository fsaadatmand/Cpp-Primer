/*
 * Exercise 10.9: Implement your own version of elimDups.  Test your program by
 * printing the vector after you read the input, after the call to unique, and
 * after the call to erase.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> &elimDups(std::vector<std::string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return words;
}

int main()
{
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle"};
	elimDups(words);
	for(const auto &word : words)
		std::cout << word << ' ';
	std::cout << '\n';
	return 0;
}
