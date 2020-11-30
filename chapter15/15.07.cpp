/*
 * Exercise 15.7: Define a class that implements a limited discount strategy,
 * which applies a discount to books purchased up to a given limit. If the
 * number of copies exceeds that limit, the normal price applies to those
 * purchased beyond the limit.
 *
 * By Faisal Saadatmand
 */

#include "15.03.h" // base class (Quote)
#include <iostream>
#include <string>

class Limited_discount : public Quote {
	public:
		Limited_discount() = default;
		Limited_discount(const std::string &book, double p, std::size_t lim, double disc)
			: Quote(book, p), limit(lim), discount(disc) { }
		double net_price(std::size_t) const override;
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

int main()
{
	unsigned price = 25, limit = 10;
	double discount = 0.5;
	Limited_discount item("3-333-33333-3", price, limit, discount);
	print_total(std::cout, item, 1);
	print_total(std::cout, item, 10);
	print_total(std::cout, item, 20);
	return 0;
}
