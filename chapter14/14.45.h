/*
 * Exercise 14.45: Write conversion operators to convert a Sales_data to string
 * and to double. What values do you think these operators should return?
 *
 * By Faisal Saadatmand
 *
 * Answer: entire data for string and revenue for double conversion operator.
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
	// friend dcl for non-members
	friend std::istream& operator>>(std::istream &, Sales_data &);
	friend std::ostream& operator<<(std::ostream &, const Sales_data &);
	friend Sales_data operator+(const Sales_data &, const Sales_data &);
	friend Sales_data operator-(const Sales_data &, const Sales_data &);
	friend bool operator==(const Sales_data &, const Sales_data &);
	friend bool operator!=(const Sales_data &, const Sales_data &);
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
	explicit operator std::string() const;
	explicit operator double() const { return revenue; }
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

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{

	return lhs.bookNo == rhs.bookNo &&
			lhs.units_sold == rhs.units_sold &&
			lhs.revenue == lhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

Sales_data::operator std::string() const
 {
	 std::string rev(std::to_string(revenue));
	 rev.erase(rev.find_last_not_of('0') + 1);
	 return bookNo + " " +
		 	std::to_string(units_sold) + " " +
			std::to_string(revenue) + " " +
			std::to_string(avg_price());
 }
#endif
