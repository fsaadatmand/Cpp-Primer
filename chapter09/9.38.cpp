/*
 * Exercise 9.38: Write a program to explore how vectors grow in the library
 * you use.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

void printSizeAndCapaity(const std::vector<int> &);

void printSizeAndCapaity(const std::vector<int> &v)
{
	std::cout << "size: " << v.size() << ' ' 
	          << " capacity: " << v.capacity() << '\n';
}

int main()
{
	std::vector<int> ivec;
	printSizeAndCapaity(ivec);

	for (std::vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	printSizeAndCapaity(ivec);
	
	ivec.reserve(50);
	printSizeAndCapaity(ivec);

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	printSizeAndCapaity(ivec);

	ivec.push_back(77);
	printSizeAndCapaity(ivec);

	ivec.shrink_to_fit();
	printSizeAndCapaity(ivec);

	return 0;
}
