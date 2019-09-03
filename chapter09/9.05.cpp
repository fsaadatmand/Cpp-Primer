/*
 * Exercise 9.5: Rewrite the previous program to return an iterator to the
 * requested element. Note that the program must handle the case where the
 * element is not found.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

std::vector<int>::iterator iteratorSafeSet(std::vector<int>::iterator,
		                std::vector<int>::iterator, const int);

std::vector<int>::iterator iteratorSafeSet(std::vector<int>::iterator begin,
		                std::vector<int>::iterator end, const int n)
{
	if (begin + n < begin || begin + n > end) {
		std::cerr << n << " is out of range."
			      << " Iterator is set to the beginning of the container\n";
		return begin;
	}
	return begin + n;
}

int main()
{
	std::vector<int> vec{34, 52, 5, 12, 94, 21, 83, 47, 47, 87};
	std::vector<int>::iterator it;

	it = iteratorSafeSet(vec.begin(), vec.end(), 1);
	std::cout << *it << '\n';
	it = iteratorSafeSet(vec.begin(), vec.end(), -1);
	std::cout << *it << '\n';
	it = iteratorSafeSet(vec.begin(), vec.end(), 11);
	std::cout << *it << '\n';
	return 0;
}
