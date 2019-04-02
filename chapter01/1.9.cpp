/*
 * Exercise 1.9: Write a program that uses a while to sum the numbers from 50
 * to 100.
 * By Faisal Saadatmand
*/

#include <iostream>

int main()
{
	int i = 50, sum = 0;

	while (i <= 100) {
		sum += i;
		i++;
	}
	std::cout << "sum of numbers of 50 to 100: " << sum << std::endl;
	return 0;
}
