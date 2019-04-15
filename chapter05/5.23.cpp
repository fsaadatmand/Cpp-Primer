/*
 * Exercise 5.23: Write a program that reads two integers from the standard
 * input and prints the result of dividing the first number by the second.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int ival1, ival2;

	std::cout << "Enter two integer numbers for division: ";
	while (std::cin >> ival1 >> ival2) {
		std::cout << ival1 / ival2 << '\n';
		std::cout << "Enter two integer numbers for division: ";
	}

	return 0;
}
