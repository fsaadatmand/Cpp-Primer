/*
 * Exercise 9.20: Write a program to copy elements from a list<int> into two
 * deques. The even-valued elements should go into one deque and the odd ones
 * into the other.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <list>
#include <deque>

int main()
{
	std::list<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::deque<int> odd, even;

	for (const auto &number : numbers)
		if (number % 2)
			odd.push_back(number);
		else
			even.push_back(number);

	std::cout << "Odd deque: ";
	for (const auto &number : odd)
		std::cout << " " << number;
	std::cout << '\n';
	std::cout << "Even deque: ";
	for (const auto &number : even)
		std::cout << " " << number;
	std::cout << '\n';
	return 0;
}
