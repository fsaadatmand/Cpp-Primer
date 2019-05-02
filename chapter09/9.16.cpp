/*
 * Exercise 9.16: Repeat the previous program, but compare elements in a
 * list<int> to a vector<int>.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v1{1, 3, 9}, v2;
	std::list<int> l1{1, 3, 9};
	v2.assign(l1.cbegin(), l1.cend());
	if (v1 == v2)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0;
}
