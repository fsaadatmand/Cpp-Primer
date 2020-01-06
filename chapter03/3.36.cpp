/*
 * Exercise 3.36: Write a program to compare two arrays for equality. Write a
 * similar program to compare two vectors.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	// compare two arrays for equality
	int a[] = {10, 20, 30, 40, 50};
	auto *aBeg = std::begin(a), *aEnd = std::end(a);
	int b[] = {10, 20, 30, 40, 50}; 
	auto *bBeg = std::begin(b), *bEnd = std::end(b);
	while (aBeg < aEnd) {
		if (*aBeg != *bBeg) {
			break;
		}
		++aBeg;
		++bBeg;
	}
	if (aBeg == aEnd && bBeg == bEnd)
		std::cout << "equal\n";
	else
		std::cout << "unequal\n";

	// compare two vectors for equality
	std::vector<int> ivec1 = {10, 20, 30, 40, 50};
	std::vector<int> ivec2 = {10, 20, 30, 40, 50, 60};
	if (ivec1 != ivec2)
		std::cout << "unequal\n";
	else
		std::cout << "equal\n";

	return 0;
}
