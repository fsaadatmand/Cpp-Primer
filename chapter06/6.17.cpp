/*
 * Exercise 6.17: Write a function to determine whether a string contains any
 * capital letters. Write a function to change a string to all lowercase. Do
 * the parameters you used in these functions have the same type? If so, why?
 * If not, why not?
 *
 * Answer: No. isAnyUpper does not need write access to s, so we use const
 * string &. tolowerS does need write access, and therefore, we used string &. 
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

bool isAnyUpper(const std::string &);
void tolowerS(std::string &);

bool isAnyUpper(const std::string &s)
{
	bool result = false;

	for (auto &c : s)
		if (isupper(c)) {
			result = true;
			break;
		}

	return result;
}

void tolowerS(std::string &s)
{
	for (auto &c : s)
		if (isupper(c))
			c = tolower(c);
}

int main()
{
	std::string str{"This a Test sTrnig"};

	std::cout << isAnyUpper(str) << '\n';
	std::cout << str << '\n';
	tolowerS(str);
	std::cout << str << '\n';

	return 0;
}
