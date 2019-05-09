/*
 * Exercise 10.35: Now print the elements in reverse order using ordinary
 * iterators.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8 , 9};
	for(auto it = ivec.cend() - 1; it >= ivec.begin(); --it)
		std::cout << *it << ' ';
	std::cout << '\n';
	return 0;
}
