/*
 * Exercise 7.7: Rewrite the transaction-processing program you wrote for the
 * exercises in § 7.1.2 (p. 260) to use these new functions.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"

std::istream& read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream& print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold <<  " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	Sales_data total;

	if (read(std::cin, total)) {
		Sales_data trans;
			while (read(std::cin, trans)) {
				if (total.isbn() == trans.isbn())
					total = add(total, trans);
				else {
					print(std::cout, total);
					std::cout << '\n';
				}
			}
			print(std::cout, total);
			std::cout << '\n';
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
