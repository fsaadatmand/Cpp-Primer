/*
 * Exercise 1.22: Write a program that reads several transactions for the same
 * ISBN. Write the sum of all transactions that were read.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item items, newItem;

	int transCount = 0;
	std::cout << "Enter items: " << std::endl;
	if (!(std::cin >> items)) {
		std::cerr << "Invalid data";
		return -1;
	}
	++transCount;
	while (std::cin >> newItem) {
// Note: ISBN check; will be introduced in the next section
		if (newItem.isbn() != items.isbn()) {
			std::cerr << "ISBN mismatch" << std::endl;
			return -1;
		}
		++transCount;
	}
	std::cout << transCount << std::endl;
	return 0;
}
