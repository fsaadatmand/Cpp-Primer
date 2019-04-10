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
	using int_array = int [colum];
//	typedef int int_array[colum];

	int ai[row][colum] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
	};

	std::cout << "Printing ai[3][4]\n";

	std::cout << "for range loop:\n";
	for (int_array &array : ai) {
		for (int &element : array)
			std::cout << element << " ";
		std::cout << '\n';
	}

	std::cout << "for loop; subscripts:\n";
	for (size_t i = 0; i != row; i++) {
		for (size_t j = 0; j != colum; j++)
			std::cout << ai[i][j] << " ";
		std::cout << '\n';
	}

	std::cout << "for loop; pointers (manual type):\n";
	for (int_array *p = ai; p != ai + row; p++) {
		for (int *q = *p; q != *p + colum; ++q) 
			std::cout << *q << " ";
		std::cout << '\n';
	}

	return 0;
}
