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

	if (std::cin >> total.bookNo && std::cin
			     >> total.units_sold && std::cin >> total.revenue) {
		Sales_data trans;
			while (std::cin >> trans.bookNo && std::cin
						 >> trans.units_sold && std::cin >> trans.revenue) {
				if (total.isbn() == trans.isbn())
					total.combine(trans);
				else {
					std::cout << total.isbn() << " "
						      << total.units_sold << " "
							  << total.revenue << " "
							  << total.avg_price() << std::endl;
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
