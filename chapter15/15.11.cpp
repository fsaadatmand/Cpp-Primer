/*
 * Exercise 15.11: Add a virtual debug function to your Quote class hierarchy
 * that displays the data members of the respective classes.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

#define VARIABLE_NAME(variable) #variable

class Quote {
	friend double print_total(std::ostream &, const Quote &, std::size_t);
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) {}
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual std::ostream& debug(std::ostream &os = std::cout,
				char step = ' ') const;
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

std::ostream&
Quote::debug(std::ostream &os, char step) const
{
	return os << VARIABLE_NAME(bookNo) << step << VARIABLE_NAME(price);
};

class Bulk_quote : public Quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &, double, std::size_t, double);
		double net_price(std::size_t) const override;
		std::ostream& debug(std::ostream &os = std::cout,
				char step = ' ') const override;
	private:
		std::size_t min_qty = 0;
	protected:
		double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string &book, double p,
		std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}

double
Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	return cnt * price;
}

std::ostream&
Bulk_quote::debug(std::ostream &os, char step) const
{
	return Quote::debug(os, step) << step << VARIABLE_NAME(min_qty)
		                          << step << VARIABLE_NAME(discount);
}

class Limited_quote : public Bulk_quote {
	public:
		Limited_quote() = default;
		Limited_quote(const std::string &, double,
				std::size_t, double,std::size_t);
		double net_price(std::size_t) const override;
		std::ostream& debug(std::ostream &os = std::cout,
				char step = ' ') const override;
	private:
		std::size_t limit;
};

Limited_quote::Limited_quote(const std::string &book, double p,
		std::size_t qty, double disc, std::size_t lim) :
		Bulk_quote(book, p, qty, disc), limit(lim) {}

double
Limited_quote::net_price(std::size_t cnt) const
{
	if (cnt <= limit) 
		return cnt * (1 - discount) * price;
	return cnt * price;
}

std::ostream&
Limited_quote::debug(std::ostream &os, char step) const
{
	return Bulk_quote::debug(os, step) << step << VARIABLE_NAME(limit);
}

int main()
{
	Quote base;
	base.debug() << std::endl;;
	Bulk_quote derived1;
	derived1.debug(std::cout, '\t') << std::endl;
	Limited_quote derived2;
	derived2.debug(std::cerr, '\n') << std::endl;
	return 0;
}
