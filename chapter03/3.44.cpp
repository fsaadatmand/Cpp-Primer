/*
 * Exercise 3.44: Rewrite the programs from the previous exercises using a type
 * alias for the type of the loop control variables.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	constexpr int row = 3, colum = 4;
	using int_array = const int [colum];
	int ai[row][colum] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
	};
	std::cout << "Printing ai[" << row << "][" << colum << "]\n";
	std::cout << "for-range:\n";
	for (const int_array &arr : ai) {
		for (const int &elem : arr)
			std::cout << ' ' << elem;
		std::cout << '\n';
	}
	std::cout << "subscripts:\n";
	for (std::size_t i = 0; i != row; ++i) {
		for (std::size_t j = 0; j != colum; ++j)
			std::cout << ' ' << ai[i][j];
		std::cout << '\n';
	}
	std::cout << "pointers:\n";
	for (const int_array *p = ai; p != ai + row; ++p) {
		for (const int *q = *p; q != *p + colum; ++q) 
			std::cout << ' ' << *q;
		std::cout << '\n';
	}
	return 0;
}
