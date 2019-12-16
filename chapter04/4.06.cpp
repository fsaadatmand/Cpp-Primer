/*
 * Exercise 4.6: Write an expression to determine whether an int value is even
 * or odd.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int x = 3;
	std::cout << (x % 2 ? "odd\n" : "even\n");
	// or
	if (x % 2)
		std::cout << "odd\n";
	else
		std::cout << "even\n";
	// or use a bitwise & operator.
	std::cout << (x & 0x01) << '\n'; // 1 is odd; 0 is even.
	return 0;
}
