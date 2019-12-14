
/*
 * Exercise 4.4: Parenthesize the following expression to show how it is
 * evaluated. Test your answer by compiling the expression (without
 * parentheses) and printing its result.
 *
 *		12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
 *
 * By Faisal Saadatmand
 *
 */

#include <iostream>

int main()
{
	std::cout << ((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)) << '\n';
	std::cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << '\n';
	return 0;
}
