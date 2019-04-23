/*
 * Exercise 7.41: Rewrite your own version of the Sales_data class to use
 * delegating constructors. Add a statement to the body of each of the
 * constructors that prints a message whenever it is executed. Write
 * declarations to construct a Sales_data object in every way possible. Study
 * the output until you are certain you understand the order of execution among
 * delegating constructors.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Sales_data {
	// friend dcl for non-members
	friend std::istream& read(std::istream &, Sales_data &);
	friend std::ostream& print(std::ostream &, const Sales_data &);
	friend Sales_data add(Sales_data &, Sales_data &);
	public:
	// constructors
//	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		       bookNo(s), units_sold(n), revenue(p * n) { } 
	Sales_data() : Sales_data("", 0, 0.0) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { }
	Sales_data(std::istream &is) : Sales_data() { read(is, *this); }
	// members
	std::string isbn() const { return bookNo;}
	Sales_data& combine(const Sales_data &);
	private:
	double avg_price() const;
	std::string bookNo;
	unsigned units_sold;
	double revenue;
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
	Sales_data book1;
	Sales_data book2("9-999-99999-9"); // string contructor
	Sales_data book3("2-222-22222-2", 5, 30); // string contructor
	Sales_data book4(std::cin); // string contructor
	Sales_data book5(std::cin); // string contructor

	print(std::cout, book1); // default constructor is used
	std::cout << '\n';
	print(std::cout, book2); // default constructor is used
	std::cout << '\n';
	print(std::cout, book3); // default constructor is used
	std::cout << '\n';
	print(std::cout, book4); // default constructor is used
	std::cout << '\n';

	return 0;
}
