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
	int a[] = {10, 20, 30, 40, 50};
	int b[] = {10, 20, 30, 40, 50};


	int *aEnd = std::end(a), *bEnd = std::end(b)
		, *pa = a, *pb = b;

	while (pa < aEnd) {
		if (*pa != *pb)
			break;
		pa++;
		pb++;
	}

	if (pa == aEnd && pb == bEnd)
		std::cout << "equal\n";
	else
		std::cout << "unequal\n";

	std::vector<int> ivec1 = {10, 20, 30, 40, 50};
	std::vector<int> ivec2 = {10, 20, 30, 40, 50, 60};

	if (ivec1 != ivec2)
		std::cout << "unequal\n";
	else
		std::cout << "equal\n";

	return 0;
}
