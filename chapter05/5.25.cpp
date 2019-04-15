/*
 * Exercise 5.25: Revise your program from the previous exercise to use a try
 * block to catch the exception. The catch clause should print a message to the
 * user and ask them to supply a new number and repeat the code inside the try.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int ival1, ival2;

	std::cout << "Enter two integers for division: ";
	while (std::cin >> ival1 >> ival2) {
		try {
			if (!ival2)
				throw std::runtime_error("ERROR: zero divisor");
			std::cout << ival1 / ival2 << '\n';
		} catch (std::runtime_error err) {
			std::cout << err.what() << "\nTry Again? (y/n) ";
			char c;
			if (!(std::cin >> c) || c == 'n')
				break;
		}
		std::cout << "Enter two integers for division: ";
	}
	return 0;
}
