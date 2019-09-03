/* 
 * Exercise 7.2: Add the combine and isbn members to the Sales_data class you
 * wrote for the exercises in § 2.6.2 (p. 76).
 *
 * By Faisal Saadatmand
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &);
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; 
	revenue += rhs.revenue;
	return *this;
}

inline double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif
