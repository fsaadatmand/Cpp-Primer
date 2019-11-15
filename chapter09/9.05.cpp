/*
 * Exercise 9.5: Rewrite the previous program to return an iterator to the
 * requested element. Note that the program must handle the case where the
 * element is not found.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

std::vector<int>::iterator contains(std::vector<int>::iterator begin,
		                std::vector<int>::iterator end, const int n)
{
	for (; begin != end; ++begin)
		if (*begin == n)
			return begin;
	return end;
}

int main()
{
	std::vector<int> vec{34, 52, 5, 12, 94, 82, 21, 83, 47, 47, 87};
	std::vector<int>::iterator it;

	for (int i = 80; i < 90; ++i) {
		it = contains(vec.begin(), vec.end(), i);
		if (it != vec.end())
			std::cout << " -> " << *it << '\n';
	}
	return 0;
}
