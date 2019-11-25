/*
 * Exercise 9.43: Write a function that takes three strings, s, oldVal, and
 * newVal. Using iterators, and the insert and erase functions replace all
 * instances of oldVal that appear in s by newVal. Test your function by using
 * it to replace common abbreviations, such as “tho” by ”though” and ”thru” by
 * “through”.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

std::string &replace_with(std::string &s,
		const std::string &oldVal, const std::string &newVal)
{
	
	for (auto it = s.begin(); it != s.end(); ++it) {
		auto pos = it; // store in case of a match
		auto pattern = oldVal.cbegin();
		for ( ; *it == *pattern; ++pattern)
			++it;
		if (pattern == oldVal.cend()) {
			pos = s.erase(pos, it);
			it = s.insert(pos, newVal.cbegin(), newVal.cend());
		}
	}
	return s;
}

int main()
{
	std::string str("tho and thru but not u");
	replace_with(str, "tho", "though");
	replace_with(str, "thru", "through");
	std::cout << str << '\n';
	return 0;
}
