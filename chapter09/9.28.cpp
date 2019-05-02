/*
 * Exercise 9.28: Write a function that takes a forward_list<string> and two
 * additional string arguments. The function should find the first string and
 * insert the second immediately following the first. If the first string is
 * not found, then insert the second string at the end of the list.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <forward_list>
#include <string>

void insertString(std::forward_list<std::string> &,
		          const std::string &, const std::string &);

void insertString(std::forward_list<std::string> &list,
		          const std::string &sought, const std::string &replace)
{
	auto prev = list.before_begin();
	auto curr = list.begin();

	while (curr != list.end())
		if (*curr == sought) {
			curr = list.insert_after(curr, replace);
			break;
		} else
			prev = curr++;
	if (curr == list.end())
		list.insert_after(prev, replace);
}

int main()
{
	std::forward_list<std::string> sflist = {"one", "two", "three", "five", "six"};
	insertString(sflist, "three", "four");
	insertString(sflist, "at the end", "seven");
	for (const auto &element : sflist)
		std::cout << element << " ";
	std::cout << '\n';
	return 0;
}
