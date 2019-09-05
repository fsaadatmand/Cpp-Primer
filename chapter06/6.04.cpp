/*
 * Exercise 6.4: Write a function that interacts with the user, asking for a
 * number and generating the factorial of that number. Call this function from
 * main.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

long unsigned fact(long unsigned val)
{
	int result = 1;
	while (val > 1)
		result *= val--;
	return result;
}
int main()
{
	int number;

	std::cout << "Enter a number to find factorial: ";
	while (std::cin >> number) {
		std::cout << number << "! is " << fact(number) << '\n';
		std::cout << "Enter a number to find factorial: ";
	}

	return 0;
}


