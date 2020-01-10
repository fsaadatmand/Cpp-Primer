/*
 * Exercise 6.17: Write a function to determine whether a string contains any
 * capital letters. Write a function to change a string to all lowercase. Do
 * the parameters you used in these functions have the same type? If so, why?
 * If not, why not?
 *
 * By Faisal Saadatmand
 */

/*
 * Answer: No. isAnyUpper does not need write access to s, so we used const
 * string & as a parameter. On the other hand, tolowerS does need write access,
 * and therefore, we used string &.
 */

#include <iostream>
#include <string>

bool isAnyUpper(const std::string &s)
{
	for (const auto &c : s)
		if (isupper(c))
			return true;
	return false;
}

void tolowerS(std::string &s)
{
	for (auto &c : s)
		c = tolower(c);
}

int main()
{
	std::string str{"This a Test sTrnig"};
	std::cout << str << '\n';
	if (isAnyUpper(str))
		tolowerS(str);
	std::cout << str << '\n';
	return 0;
}
