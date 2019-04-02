/*
 * Exercise 1.22: Write a program that reads several transactions for the same
 * ISBN. Write the sum of all transactions that were read.
 * the same ISBN and produces their sum. 
 * by Faisal Saadatmand
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item items, newItem;

	std::cout << "Enter items: " << std::endl;
	std::cin >> items;
	while (std::cin >> newItem)
		items += newItem;
	std::cout << items << std::endl;
	return 0;
}
