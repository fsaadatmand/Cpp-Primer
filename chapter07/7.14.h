/*
 * Exercise 7.14: Write a version of the default constructor that explicitly
 * initializes the members to the values we have provided as in-class
 * initializers.
 *
 * By Faisal Saadatmand
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data;
std::istream& read(std::istream &, Sales_data &);

struct Sales_data {
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n) { } 
	Sales_data(std::istream &is) { read(is, *this); }
	// members
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &);
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// member function's definitions
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; 
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

// non-member function's declarations
std::ostream& print(std::ostream &, const Sales_data &);
Sales_data add(Sales_data &, Sales_data &);
#endif
