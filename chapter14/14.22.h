/*
 * Exercise 14.22: Define a version of the assignment operator that can assign
 * a string representing an ISBN to a Sales_data.
 *
 * By Faisal Saadatmand
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
	// friend dcl for non-members
	friend std::istream& operator>>(std::istream &, Sales_data &);
	friend std::ostream& operator<<(std::ostream &, const Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data operator-(const Sales_data &, const Sales_data &);
	public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n) { } 
	explicit Sales_data(std::istream &is) { operator>>(is, *this); }
	// members
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &);
	Sales_data& operator+=(const Sales_data &);
	Sales_data& operator-=(const Sales_data &);
	Sales_data& operator=(const std::string &);
	private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// member function's definitions
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
	return 0;
}

Sales_data&
Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data&
Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data&
Sales_data::operator=(const std::string &isbn)
{
	bookNo = isbn;
	return *this;
}

// non-member function's declarations
std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold <<  " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data total = lhs;
	total -= rhs;
	return total;
}
#endif
