/*
 * Exercise 1.16: Write your own version of a program that prints the sum of a
 * set of integers read from cin.
 *
 * by Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int value, sum;

	sum = 0;
	std::cout << "Enter a set of numbers: ";
	while (std::cin >> value)
		sum += value;
	std::cout << std::endl << sum << std::endl;
	return 0;
}
