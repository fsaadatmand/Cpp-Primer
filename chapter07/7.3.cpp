/*
 * Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
 * 256) to use these members.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total;
	double price = 0.0;

	if (std::cin >> total.bookNo && std::cin
			     >> total.units_sold && std::cin >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
			while (std::cin >> trans.bookNo && std::cin
						 >> trans.units_sold && std::cin >> price) {
				trans.revenue = trans.units_sold * price;
				if (total.isbn() == trans.isbn()) {
					total.combine(trans);
				} else {
					std::cout << total.isbn() << " "
						      << total.units_sold << " "
							  << total.revenue << " "
							  << total.avg_price() << std::endl;
					total = trans;
				}
			}
			std::cout << total.isbn() << " "
				<< total.units_sold << " "
				<< total.revenue << " "
				<< total.avg_price() << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
