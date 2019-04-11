/*
 * Exercise 3.43: Write three different versions of a program to print the
 * elements of ia. One version should use a range for to manage the iteration,
 * the other two should use an ordinary for loop in one case using subscripts
 * and in the other using pointers. In all three programs write all the types
 * directly. That is, do not use a type alias, auto, or decltype to simplify
 * the code.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	constexpr int row = 3, colum = 4;

	int ai[row][colum] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
	};

	std::cout << "Printing ai[" << row << "][" << colum << "]\n";

	std::cout << "for range loop:\n";
	for (int (&array)[colum] : ai) {
		for (int &element : array)
			std::cout << element << " ";
		std::cout << '\n';
	}

	std::cout << "for loop - subscripts:\n";
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != colum; j++)
			std::cout << ai[i][j] << " ";
		std::cout << '\n';
	}

	std::cout << "for loop - pointers:\n";
	for (int (*p)[colum] = ai; p != ai + row; p++) {
		for (int *q = *p; q != *p + colum; ++q) 
			std::cout << *q << " ";
		std::cout << '\n';
	}

	return 0;
}
