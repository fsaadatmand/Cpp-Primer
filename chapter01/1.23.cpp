/*
 * Exercise 1.23: Write a program that reads several transactions and counts
 * how many transactions occur for each ISBN.
 *
by Faisal Saadatmand
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
			std::cout << currItem.isbn() << " " << count <<  std::endl;
			currItem = item;
			count = 1;
		}
	std::cout << currItem.isbn() << " " << count << std::endl;
	return 0;
}
