/*
 * Exercise 4.10: Write the condition for a while loop that would read ints
 * from the standard input and stop when the value read is equal to 42.
 *
 * Note: the loop does not test for valid input.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	long int x;

	std::cin >> x;
	while (x != 42) {
		std::cin >> x;
		std::cout << x << '\n';
	}
	return 0;
}
