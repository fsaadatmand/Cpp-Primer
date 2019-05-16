/*
 * Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to
 * use insert instead of subscripting. Which program do you think is easier to
 * write and read? Explain your reasoning.
 *
 * By Faisal Saadatmand
 *
 * Answer: the subscript version seems easier. There is less to deal with. The
 * insert version, requires an iterator of type pair and a test of the
 * returned value of the insert operation which is a pair of the container's
 * key type and a bool.  Moreover, the insertion through the iterator also
 * requires two levels of indirections, into the pair and the map iterator.
 */

#include <iostream>
#include <map>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;

	while (std::cin >> word) {
		auto ret = word_count.insert({word, 0});
			++ret.first->second;
	}
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time") << '\n';
	return 0;
}
