/*
 * Exercise 18.9: Define the bookstore exception classes described in this
 * section and rewrite your Sales_data compound assigment operator to throw an
 * exception.
 *
 * By Faisal Saadatmand
 */
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <unordered_set>

class out_of_stock : public std::runtime_error {
	public:
		explicit out_of_stock(const std::string &s) :
			std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error {
	public:
		explicit isbn_mismatch(const std::string &s) :
			std::logic_error(s) {}
		isbn_mismatch(const std::string &s,
				const std::string &lhs, const std::string &rhs) :
			std::logic_error(s), left(lhs), right(rhs) {}
		std::string left, right;
};

class Sales_data {
	// friend dcl for non-members
	friend std::istream& operator>>(std::istream &, Sales_data &);
	friend std::ostream& operator<<(std::ostream &, const Sales_data &);
	friend bool operator==(const Sales_data &, const Sales_data &);
	public:
	// constructors
	Sales_data() noexcept = default;
	Sales_data(const std::string &s) noexcept : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) noexcept :
		       bookNo(s), units_sold(n), revenue(p * n) { } 
	explicit Sales_data(std::istream &is) { operator>>(is, *this); }
	// members
	std::string isbn() const { return bookNo;}
	Sales_data& operator+=(const Sales_data &);
	Sales_data& operator-=(const Sales_data &);
	private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// member function's definitions
inline double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

// non-member function's definitions
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

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold <<  " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.bookNo == rhs.bookNo &&
		   lhs.units_sold == rhs.units_sold &&
		   lhs.revenue == rhs.revenue;
}

inline bool operator!=(const Sales_data& lhs, const Sales_data& rhs)
{
	return !(lhs == rhs);
}

Sales_data&
Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data&
Sales_data::operator-=(const Sales_data &rhs)
{
	units_sold -= rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
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
