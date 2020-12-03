/*
 * Exercise 15.11: Add a virtual debug function to your Quote class hierarchy
 * that displays the data members of the respective classes.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Quote {
	friend double print_total(std::ostream &, const Quote &, std::size_t);
	public:
		Quote() = default;
		Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) { }
		virtual ~Quote() = default;
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual std::ostream& debug(std::ostream &os = std::cout, const std::string &step = ", ") const;
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

inline
std::ostream&
Quote::debug(std::ostream &os, const std::string &step) const
{
	return os << "{\'bookNo\': \'" << bookNo << "\'" << step << "\'price\': \'" << price << "\'}";
};

class Bulk_quote : public Quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &, double, std::size_t, double);
		double net_price(std::size_t) const override;
		std::ostream& debug(std::ostream &os = std::cout, const std::string &step = ", ") const override;
	private:
		std::size_t min_qty = 0;
		double discount = 0.0;
};

inline
Bulk_quote::Bulk_quote(const std::string &book, double p,
		std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}

inline
double
Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	return cnt * price;
}

inline
std::ostream&
Bulk_quote::debug(std::ostream &os, const std::string &step) const
{
	return Quote::debug(os, step) << '\b' << step << "\'min_qt\': " << min_qty
		                          << step << "\'discount\': " << discount << '}';
}

class Limited_discount : public Quote {
	public:
		Limited_discount() = default;
		Limited_discount(const std::string &book, double p, std::size_t lim, double disc)
			: Quote(book, p), limit(lim), discount(disc) { }
		double net_price(std::size_t) const override;
		std::ostream& debug(std::ostream &os = std::cout, const std::string &step = ", ") const override;
	private:
		std::size_t limit = 0;
		double discount = 0.0;
};

inline
double
Limited_discount::net_price(std::size_t cnt) const
{
	if (cnt > limit) {
		auto discounted = limit * (1 - discount) * price;
		auto regularPrice = (cnt - limit) * price;
		return discounted + regularPrice;
	}
	return cnt * (1 - discount) * price;
}

inline
std::ostream&
Limited_discount::debug(std::ostream &os, const std::string &step) const
{
	return Quote::debug(os, step) << '\b' << step << "\'limit\': " << limit
		                          << step << "\'discount\': " << discount << '}';
}

int main()
{
	Quote base("2-222222-2", 25);
	base.debug() << '\n';
	Bulk_quote derived1("3-333333-3", 35, 10, 0.25);
	derived1.debug(std::cout) << '\n';
	Limited_discount derived2("4-444444-4", 42, 10, 0.5);
	derived2.debug(std::cerr) << '\n';
	return 0;
}
