/*
 * Exercise 3.45: Rewrite the programs again, this time using auto.
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
	std::cout << "for-range:\n";
	for (const auto &arr : ai) {
		for (const auto &elem : arr)
			std::cout << ' ' << elem;
		std::cout << '\n';
	}
	std::cout << "subscripts:\n";
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != colum; j++)
			std::cout << ' ' << ai[i][j];
		std::cout << '\n';
	}
	std::cout << "pointers:\n";
	for (const auto *p = ai; p != ai + row; p++) {
		for (const auto *q = *p; q != *p + colum; ++q) 
			std::cout << ' ' << *q;
		std::cout << '\n';
	}
	return 0;
}
