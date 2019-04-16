/*
 * Exercise 6.27: Write a function that takes an initializer_list<int> and
 * produces the sum of the elements in the list.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <initializer_list>

int sumOfList(std::initializer_list<int>);

int sumOfList(std::initializer_list<int> li)
{
	int sum = 0;
	for (const auto &element : li)
		sum += element;
	return sum;
}

int main()
{
	int x = 10, result = 0;

	result = sumOfList({3, 5, 6, 7, x});
	std::cout << result << '\n';

	return 0;
}
