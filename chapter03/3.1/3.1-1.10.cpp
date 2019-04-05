/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with approriate using declarations.
 *
 * Exercise 1.10: In addition to the ++ operator that adds 1 to its operand,
 * there is decrement operator (--) that subtracts 1. Use the decrement
 * operator to write a while that prints the numbers from ten down to zero.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cout; using std::endl;

int main()
{
	int i = 10;

	while (i >= 0)
		cout << i-- << endl;
	return 0;
}
