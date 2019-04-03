/*
 * Exercise 1.24: Test the previous program by giving multiple transactions
 * representing multiple ISBNs. The records for each ISBN should be grouped
 * together.
 * by Faisal Saadatmand
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item currItem, item;

	std::cout << "Enter transactions:" << std::endl;
	if (!(std::cin >> currItem)) {
		std::cerr << "Ivalid data" << std::endl;;
		return -1;
	}
	int count = 1;
	while (std::cin >> item)
		if (currItem.isbn() == item.isbn())
			count++;
		else {
			std::cout << currItem.isbn() << " " << count << std::endl;
			currItem = item;
			count = 1;
		}
	std::cout << currItem.isbn() << " " << count << std::endl;
	return 0;
}
