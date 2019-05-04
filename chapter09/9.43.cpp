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

std::string &replaceInString(std::string &,
		const std::string &, const std::string &);

std::string &replaceInString(std::string &s,
		const std::string &oldVal, const std::string &newVal)
{
	
	for (auto ix = s.begin(); ix != s.end(); ++ix) {
		auto pos = ix;                 // save position of potential match
		auto jx = oldVal.cbegin();
		for(; ix != s.end() && jx != oldVal.cend() && *ix == *jx; ++jx, ++ix)
			;
		if (jx == oldVal.cend()) {
			pos = s.erase(pos, ix);
			ix = s.insert(pos, newVal.cbegin(), newVal.cend()); 
		}
	}
	return s;
}

int main()
{
	std::string str("tho and thru but not u");
	replaceInString(str, "tho", "though");
	replaceInString(str, "thru", "through");
	std::cout << str << '\n';
	return 0;
}
