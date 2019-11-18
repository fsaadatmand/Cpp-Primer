/*
 * Exercise 6.38: Revise the arrPtr function on to return a reference to the
 * array.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int odd[]{1, 3, 5, 7, 9};
int even[]{0, 2, 4, 6, 8};

decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even; // return a pointer to an array
}

decltype(odd)& arrRef(int i)
{
	return (i % 2) ? odd : even; // return a reference to an array
}

int main()
{
	constexpr size_t size = sizeof(odd) / sizeof(odd[0]);
	// decltype(odd)* arrPtr(int)
	auto pa = arrPtr(2); // pa's type is int (*pa)[size]
	for (size_t i = 0; i < size; ++i)
		std::cout << ' ' << (*pa)[i];
	std::cout << '\n';
	// decltype(odd)& arrRef(int)
	auto ra = arrRef(3); // ra's type is int (&ra)[size]
	for (size_t i = 0; i < size; ++i)
		std::cout << ' ' << ra[i];
	std::cout << '\n';
}
