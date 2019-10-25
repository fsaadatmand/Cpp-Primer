/*
 * Exercise 10.20: The library defines an algorithm named count_if. Like
 * find_if, this function takes a pair of iterators denoting an input range and
 * a predicate that it applies to each element in the given range. count_if
 * returns a count of how often the predicate is true. Use count_if to rewrite
 * the portion of our program that counted how many words are greater than
 * length 6.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string make_plural(std::size_t ctr, const std::string &word,
						const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::string conjugate(std::size_t ctr, const std::string &singular,
					  const std::string &plural)
{
	return (ctr > 1) ? plural : singular;
}

int main()
{
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle",
								   "sixteen", "times"};
	constexpr std::string::size_type size{6};
	auto count = count_if(words.begin(), words.end(),
			[&] (const std::string &word) { return word.size() > size; });
	std::cout << count << make_plural(count, " word", "s")
			  << conjugate(count, " has ", " have ")
			  << "more than " << size << " letters" << '\n';
	return 0;
}
