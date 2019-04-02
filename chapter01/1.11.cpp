/*
 * Exercise 1.11: Write a program that prompts the user for two integers. Print
 * each number in the range specified by those two integers.
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int start, end;

	std::cout << "Enter to integers to print numbers within range: ";
	std::cin >> start >> end;
	while (start <= end)
		std::cout << start++ << " ";
	std::cout << std::endl;
	return 0;
}
