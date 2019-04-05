/*
 * Exercise 2.42: Write your own version of the Sales_data.h header and use it
 * to rewrite the exercise from § 2.6.2 (p. 76).
 *
 * Exercise 1.22: Write a program that reads several transactions for the same
 * ISBN. Write the sum of all the transactions that were read.
 *
 * By Faisal Saadatmand
*/

#include <iostream>
#include "SALES_DATA_H.h"

int main()
{
	Sales_data items, newItem;
	double price = 0.0;
	int transCount = 0;

	if (!(std::cin >> items.bookNo >> items.units_sold >> price)) {
		std::cerr << "Invalid data";
		return -1;
	}
	++transCount;
	while (std::cin >>	newItem.bookNo >> newItem.units_sold >> price) {
		if (newItem.bookNo != items.bookNo) {
			std::cerr << "ISBN mismatch" << std::endl;
			return -1;
		}
		++transCount;
	}
	std::cout << "Number of transactions: " << transCount << std::endl;
	return 0;
}
