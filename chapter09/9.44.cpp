/*
 * Exercise 9.44: Rewrite the previous function using an index and replace.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

std::string &replaceInString(std::string &s, 
		const std::string &oldVal, const std::string &newVal)
{
	for (decltype(s.size()) i = 0; i < s.size(); ++i) {
		auto pos = i; // store in case of a match
		decltype(oldVal.size()) j = 0; 
		for(; s[i] == oldVal[j]; ++j, ++i)
			;
		if (j == oldVal.size()) {
			s.replace(pos, oldVal.size(), newVal);
			i = pos + newVal.size();  // update index of s
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
