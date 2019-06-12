/*
 * Exercise 15.15: Define your own versions of Disc_quote and Bulk_quote.
 *
 * By Faisal Saadatmand
 */

#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

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
				   Quote(book, price),
				   quantity(qty), discount(disc) {}
		double net_price(std::size_t) const = 0; // pure virtual function
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &book, double price,
				std::size_t qty, double disc) :
			Disc_quote(book, price, qty, disc) {}
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
