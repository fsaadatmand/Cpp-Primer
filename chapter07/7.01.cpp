/*
 * Exercise 7.1: Write a version of the transaction-processing program from §
 * 1.6 (p. 24) using the Sales_data class you defined for the exercises in §
 * 2.6.1 (p. 72).
 *
 * By Faisal Saadatmand
 */

#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;
	double averagePrice = 0.0;
	double price = 0.0;
	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
				averagePrice = total.revenue / total.units_sold;
			} else {
				std::cout << total.bookNo << " "
					<< total.units_sold << " "
					<< total.revenue << " "
					<< averagePrice << std::endl;
				total = trans;
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
