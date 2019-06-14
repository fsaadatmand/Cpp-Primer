/*
 * Exercise 15.27: Redefine your Bulk_quote class to inherit its constructors.
 *
 * By Faisal Saadatmand
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <utility>

class Quote {
	friend double print_total(std::ostream &, const Quote &, std::size_t);
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual ~Quote() {};
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() 
	   << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

class Disc_quote : public Quote {
	public:
		Disc_quote() = default;
		Disc_quote(const std::string &book, double price,
				std::size_t qty, double disc) :
				   Quote(book, price), quantity(qty), discount(disc) {}
		double net_price(std::size_t) const = 0; // pure virtual function
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
	public:
		// default constructor is synthesized
		using Disc_quote::Disc_quote; // inherit constructors
		double net_price(std::size_t) const override;
};

double
Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	return cnt * price;
}
#endif
