/*
 * Exercise 6.38: Revise the arrPtr function on to return a reference to the
 * array.
 *
 * By Faisal Saadatmand
 */

#define SIZE sizeof(odd) / sizeof(odd[0])

#include <iostream>

int odd[]{1, 3, 5, 7, 9};
int even[]{0, 2, 4, 6, 8};
int (&rOdd)[SIZE]{odd}, (&rEven)[SIZE]{even};

decltype(odd) *arrtPtr(int i)
{
	return (i % 2) ? &odd : &even; // return a pointer to an array
}

decltype(odd) &arrtRef(int i)
{
	return (i % 2) ? rOdd : rEven; // return a reference to an array
}

int main() {
	int (*pa)[SIZE];

	pa = arrtPtr(3);
	for (size_t i = 0; i < SIZE; ++i)
		std::cout << (*pa)[i] << " ";
	std::cout << '\n';

	int (&ra)[SIZE] = arrtRef(3);
	for (size_t i = 0; i < SIZE; ++i)
		std::cout << ra[i] << " ";
	std::cout << '\n';
}
