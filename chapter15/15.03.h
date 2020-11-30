/*
 * Exercise 15.3: Define your own versions of the Quote class and the
 * print_total function.
 *
 * By Faisal Saadatmand
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>

class Quote {
	friend double print_total(std::ostream &, const Quote &, std::size_t);
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

inline
double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() 
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

#endif
