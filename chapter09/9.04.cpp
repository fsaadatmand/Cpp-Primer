/*
 * Exercise 9.4: Write a function that takes a pair of iterators to a
 * vector<int> and an int value. Look for that value in the range and return a
 * bool indicating whether it was found.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

bool contains(std::vector<int>::const_iterator begin,
		                std::vector<int>::const_iterator end, const int n)
{
	for (; begin != end; ++begin)
		if (*begin == n)
			return true;
	return false;
}

int main()
{
	std::vector<int> vec{34, 52, 5, 12, 94, 82, 21, 83, 47, 47, 87};

	for (int i = 80; i < 90; ++i)
		if (contains(vec.begin(), vec.end(), i))
			std::cout <<  i << " -> Found\n";
		else
			std::cout << i << " -> Not found\n";
	return 0;
}
