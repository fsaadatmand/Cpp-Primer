/*
 * Exercise 15.7: Define a class that implements a limited discount strategy,
 * which applies a discount to books purchased up to a given limit. If the
 * number of copies exceeds that limit, the normal price applies to those
 * purchased beyond the limit.
 *
 * By Faisal Saadatmand
 */

#ifndef LIMITED_QUOTE_H
#define LIMITED_QUOTE_H

#include <string>
#include "15.15.h" // Disc_quote

class Limited_quote : public Disc_quote {
	public:
		Limited_quote() = default;
		Limited_quote(const std::string &, double,
				std::size_t, double);
		double net_price(std::size_t) const override;
};

Limited_quote::Limited_quote(const std::string &book, double price,
		std::size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {}

double
Limited_quote::net_price(std::size_t cnt) const
{
	if (cnt <= quantity) 
		return cnt * (1 - discount) * price;
	return cnt * price;
}
#endif
