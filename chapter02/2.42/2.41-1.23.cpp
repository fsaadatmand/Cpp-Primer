/*
 * Exercise 2.42: Write your own version of the Sales_data.h header and use it
 * to rewrite the exercise from § 2.6.2 (p. 76).
 *
 * Exercise 1.23: Write a program that reads several transactions and counts
 * how many transactions occur for each ISBN.
 *
 * By Faisal Saadatmand
*/

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data currItem, item;
	double price = 0.0;
	int transCount = 0;

	std::cout << "Enter transactions:" << std::endl;
	if (!(std::cin >> currItem.bookNo >> currItem.units_sold >> price)) {
		std::cerr << "Ivalid data" << std::endl;;
		return -1;
	}
	++transCount;
	while (std::cin >> item.bookNo >> item.units_sold >> price)
		if (currItem.bookNo == item.bookNo)
			transCount++;
		else {
			std::cout << currItem.bookNo << " " << transCount <<  std::endl;
			currItem = item;
			transCount = 1;
		}
	std::cout << currItem.bookNo << " " << transCount << std::endl;
	return 0;
}
