/*
 * Exercise 10.2: Repeat the previous program, but read values into a list of
 * strings.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main()
{
	std::list<std::string> slist;
	const std::string value{"beer"};
	std::string word;
	while (std::cin >> word)
		slist.push_back(word);
	std::cout << count(slist.cbegin(), slist.cend(), value) 
		      << " elements have the value " << value << '\n';
	return 0;
}
