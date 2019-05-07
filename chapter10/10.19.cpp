/*
 * Exercise 10.19: Rewrite the previous exercise to use stable_partition, which
 * like stable_sort maintains the original element order in the paritioned
 * sequence.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimDups(std::vector<std::string> &words)
{
	sort(words.begin(), words.end());
	auto end_uniqe = unique(words.begin(), words.end());
	words.erase(end_uniqe, words.end());
}

std::string make_plural(size_t ctr, const std::string &word,
		                            const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
		const std::vector<std::string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
			[] (const std::string &s1, const std::string &s2)
			   { return s1.size() < s2.size(); });
	auto wc = stable_partition(words.begin(), words.end(),
			[sz] (const std::string &word) { return word.size() >= sz; });
	auto count = wc - words.begin();
	std::cout << count << ' ' << make_plural(count, "word", "s")
		      << " of length "<< sz << " or longer" << '\n';
	for_each(words.begin(), wc,
			[] (const std::string &s) { std::cout << s << ' '; });
}

int main()
{
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle"};
	constexpr std::string::size_type size = 5;
	biggies(words, size);
	std::cout << std::endl;
	return 0;
}
