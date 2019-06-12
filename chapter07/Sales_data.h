#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

class Sales_data {
	// friend dcl for non-members
	friend std::istream& read(std::istream &, Sales_data &);
	friend std::ostream& print(std::ostream &, const Sales_data &);
	friend Sales_data add(Sales_data &, Sales_data &);
	public:
		// constructors
		Sales_data() = default;
		Sales_data(const std::string &s) : bookNo(s) { }
		Sales_data(const std::string &s, unsigned n, double p) :
			bookNo(s), units_sold(n), revenue(p * n) { } 
		explicit Sales_data(std::istream &is) { read(is, *this); }
		// members
		std::string isbn() const { return bookNo;}
		Sales_data& combine(const Sales_data &);
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
	else
		return 0;
}

// non-member function's declarations
std::istream& read(std::istream &, Sales_data &);
std::ostream& print(std::ostream &, const Sales_data &);
Sales_data add(Sales_data &, Sales_data &);
#endif
