/*
 * Exercise 2.42: Write your own version of the Sales_data.h header and use it
 * to rewrite the exercise from § 2.6.2 (p. 76).
 *
 * Exercise 1.21: Write a program that reads two Sales_item objects that have the
 * same ISBN and produces their sum.
 *
 * By Faisal Saadatmand
*/

#include <iostream>
#include "SALES_DATA_H.h"

int main()
{
	Sales_data item1, item2;

	double price = 0;
	std::cin >> item1.bookNo >> item1.units_sold >> price;
	item1.revenue = item1.units_sold * price;
	std::cin >> item2.bookNo >> item2.units_sold >> price;
	item2.revenue = item2.units_sold * price;

	if (item1.bookNo != item2.bookNo) {
		std::cerr << "ISBN mismatch" << std::endl;
		return -1;
	}

	unsigned totalCount = item1.units_sold + item2.units_sold;
	double totalRevenue = item1.revenue + item2.revenue;
	std::cout << item1.bookNo << " " << totalCount << " " 
		      << totalRevenue << std::endl;

	if (totalCount != 0)
		std::cout << totalRevenue/totalCount << std::endl;
	else
		std::cout << "(no sales)" << std::endl;

	return 0;
}
