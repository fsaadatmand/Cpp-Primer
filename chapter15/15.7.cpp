/*
 * Exercise 15.7: Define a class that implements a limited discount strategy,
 * which applies a discount to books purchased up to a given limit. If the
 * number of copies exceeds that limit, the normal price applies to those
 * purchased beyond the limit.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include "15.5.h" // base class (Bulk_quote)

class Limited_quote : public Bulk_quote {
	public:
		Limited_quote() = default;
		Limited_quote(const std::string &, double,
				std::size_t, double,std::size_t);
		double net_price(std::size_t) const override;
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

int main()
{
	unsigned price = 25, limit;
	double units_sold = 5, discount = 0.5;
	Limited_quote item("3-333-33333-3", price,
			units_sold, discount, limit);
	print_total(std::cout, item, 1);
	print_total(std::cout, item, 10);
	print_total(std::cout, item, 11);
	return 0;
}
