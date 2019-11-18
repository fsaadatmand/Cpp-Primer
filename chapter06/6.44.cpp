/*
 * Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be
 * inline.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

inline bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}

int main() {
	std::string str1{"hello"};
	std::string str2{"hello!!"};
	std::cout << isShorter(str1, str2) << '\n';
	return 0;
}
