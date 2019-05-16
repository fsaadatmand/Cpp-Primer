/*
 * Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and
 * word-transformation (§ 11.3.6, p. 440) programs to use an unordered_map.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, size_t> word_count;
	std::string word;
	while (std::cin >> word)
		++word_count[word];
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			      << ((w.second > 1) ? " times" : "time") << '\n';
	return 0;
}
