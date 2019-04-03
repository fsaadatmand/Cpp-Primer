/*
 * Exercise 1.19: Revise the program you wrote for the exercises in § 1.4.1 (p.
 * 13) that printed a range of numbers so that it handles input in which the
 * first number is smaller.
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int start, end;

	std::cout << "Enter to integers to print numbers within range: ";
	std::cin >> start >> end;
	if (start >= end) {
		std::cerr << "Invalid range" << std::endl;
		return -1;
	}
	while (start <= end)
		std::cout << start++ << " ";
	std::cout << std::endl;
	return 0;
}
