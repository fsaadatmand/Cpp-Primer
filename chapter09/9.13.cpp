/*
 * Exercise 9.13: How would you initialize a vector<double> from a list<int>?
 *
 * Answer: by using the constructor that takes input iterators. Note that an
 * implicit conversion of each each element (from int to double) will take
 * place during the initialization.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int> l1{77, 39, 72, 37, 41};
	std::vector<double> v1(l1.cbegin(), l1.cend());

	for (const auto &elem : v1)
		std::cout << " " << elem;
	std::cout << '\n';
	return 0;
}
