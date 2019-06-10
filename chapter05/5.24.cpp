/*
 * Exercise 5.24: Revise your program to throw an exception if the second
 * number is zero. Test your program with a zero input to see what happens on
 * your system if you don’t catch an exception.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int ival1, ival2;
	while (std::cout << "Enter two integer numbers for division:\n" &&
			std::cin >> ival1 >> ival2) {
		if (!ival2)
			throw std::runtime_error("zero divisor");
		std::cout << ival1 / ival2 << '\n';
	}
	return 0;
}
