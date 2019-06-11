/*
 * Exercise 15.5: Define your own version of the Bulk_quote class.
 *
 * By Faisal Saadatmand
 */

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "15.3.h" // base class (Quote)

class Bulk_quote : public Quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &, double, std::size_t, double);
		double net_price(std::size_t) const override;
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
#endif

