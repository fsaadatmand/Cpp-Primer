/*
 * Exercise 2.42: Write your own version of the Sales_data.h header and use it
 * to rewrite the exercise from § 2.6.2 (p. 76).
 *
 * Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
 * execute the bookstore program presented in this section.
 *
 * By Faisal Saadatmand
*/

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total;        // variable to hold data for the next transaction
	double price = 0, averagePrice = 0;

	if (std::cin >> total.bookNo >> total.units_sold >> price) { //read first trans
		total.revenue = total.units_sold * price;
		Sales_data trans;    // variable to hold the running sum;
		while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				averagePrice = total.revenue / total.units_sold;
				std::cout << total.bookNo << " "
					      << total.units_sold << " "
					      << total.revenue << " "
					      << averagePrice << std::endl;  // print previous book result
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		averagePrice = total.revenue / total.units_sold;
		std::cout << total.bookNo << " " 
			      << total.units_sold << " "
				  << total.revenue << " " 
				  << averagePrice << std::endl;   // print the last transaction
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
