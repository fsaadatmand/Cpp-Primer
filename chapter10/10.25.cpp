/*
 * Exercise 10.25: In the exercises for § 10.3.2 (p. 392) you wrote a version
 * of biggies that uses partition. Rewrite that function to use check_size and
 * bind.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

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

bool check_size(const std::string &s, std::string::size_type size)
{
	return s.size() >= size;
}

void biggies(std::vector<std::string> &words,
		const std::vector<std::string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
			[] (const std::string &s1, const std::string &s2)
			   { return s1.size() < s2.size(); });
	auto wc = partition(words.begin(), words.end(),
			bind(check_size, std::placeholders::_1, sz));
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
