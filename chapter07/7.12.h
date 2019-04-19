/* 
 * Exercise 7.12: Move the definition of the Sales_data constructor that takes
 * an istream into the body of the Sales_data class.
 *
 * Note: read is not a member function, as such, it cannot be included in the
 * class' body without a previous declaration. I moved up the non-member
 * declarations to the top of the header file.
 *
 * By Faisal Saadatmand
 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

// non-member function's declarations
struct Sales_data;
std::istream& read(std::istream &, Sales_data &);
std::ostream& print(std::ostream &, const Sales_data &);
Sales_data add(Sales_data &, Sales_data &);

struct Sales_data {
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n) { } 
	Sales_data(std::istream &is) { read(is, *this); }   // read needs decl above
	// members
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &);
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
	else
		return 0;
}

#endif
