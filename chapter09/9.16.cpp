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
	std::vector<int> v1{1, 3, 9};
	std::list<int> l1{1, 3, 9};
	if (v1 == std::vector<int>(l1.begin(), l1.end())) /* temporary vector */
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0;
}
