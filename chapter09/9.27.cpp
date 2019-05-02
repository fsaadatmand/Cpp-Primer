/*
 * Exercise 9.27: Write a program to find and remove the odd-valued elements in
 * a forward_list<int>.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> fl = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto prev = fl.before_begin();
	auto curr = fl.begin();

	while (curr != fl.end())
		if (*curr % 2)
			curr = fl.erase_after(prev);
		else 
			prev = curr++;

	for (const auto &element : fl)
		std::cout << element << " ";
	std::cout << '\n';

	return 0;
}
