
/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with approriate using declarations.
 *
 * Exercise 1.9: Write a program that uses a while to sum the numbers from 50
 * to 100.
 * By Faisal Saadatmand
*/

#include <iostream>

using std::cout; using std::endl;

int main()
{
	int i = 50, sum = 0;

	while (i <= 100) {
		sum += i;
		i++;
	}
	cout << "sum of numbers from 50 to 100 is " << sum << endl;
	return 0;
}
