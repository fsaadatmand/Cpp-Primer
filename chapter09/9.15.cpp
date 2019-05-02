/*
 * Exercise 9.15: Write a program to determine whether two vector<int>s are
 * equal.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1{1, 3, 9}, v2{1, 3, 9};

	if (v1 == v2)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0;
}
