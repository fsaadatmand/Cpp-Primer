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
	int factorial = 1;
	while (val > 1)
		factorial *= val--;
	return factorial;
}

unsigned long cal_fact()
{
	long unsigned number;
	std::cout << "Enter a number to find its factorial: ";
	if (!(std::cin >> number))
		return 0;
	return fact(number);
}

int main()
{
	auto result = cal_fact();
	if (result)
		std::cout << result << '\n';
	return 0;
}
