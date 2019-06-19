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
