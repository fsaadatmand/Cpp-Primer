/*
 * Exercise 4.10: Write the condition for a while loop that would read ints
 * from the standard input and stop when the value read is equal to 42.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int x;
	while ((std::cin >> x) && x != 42)
		std::cout << x << '\n';
	return 0;
}
