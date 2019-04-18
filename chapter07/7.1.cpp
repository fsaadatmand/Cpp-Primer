/*
 * Exercise 7.1: Write a version of the transaction-processing program from §
 * 1.6 (p. 24) using the Sales_data class you defined for the exercises in §
 * 2.6.1 (p. 72).
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total;
	double averagePrice = 0.0;

	if (std::cin >> total.bookNo && std::cin
			     >> total.units_sold && std::cin >> total.revenue) {
		Sales_data trans;
			while (std::cin >> trans.bookNo && std::cin
						 >> trans.units_sold && std::cin >> trans.revenue) {
				if (total.bookNo == trans.bookNo) {
					total.units_sold += trans.units_sold;
					total.revenue += trans.revenue;
					averagePrice = total.revenue / total.units_sold;
				} else {
					std::cout << total.bookNo << " "
						      << total.units_sold << " "
							  << total.revenue << " "
							  << averagePrice << std::endl;
				}
			}
			std::cout << total.bookNo << " "
				<< total.units_sold << " "
				<< total.revenue << " "
				<< averagePrice << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
