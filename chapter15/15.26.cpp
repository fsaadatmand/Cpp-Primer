/*
 * Exercise 15.26: Define the Quote and Bulk_quote copy-control members to do
 * the same job as the synthesized versions. Give them and the other
 * constructors print statements that identify which function is running.
 * Write programs using these classes and predict what objects will be created
 * and destroyed. Compare your predictions with the output and continue
 * experimenting until your predictions are reliably correct.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <utility>

class Quote {
	friend double print_total(std::ostream &, const Quote &, std::size_t);
	public:
		Quote() = default;
		Quote(const Quote &b) : bookNo(b.bookNo), price(b.price)
			{ std::cout << "Quote(const Quote &)\n"; } 
		Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) {}
		Quote(Quote &&b) noexcept : bookNo(b.bookNo), price(b.price)
			{ std::cout << "Quote(Quote &&b)\n"; }
		Quote& operator=(const Quote &);
		Quote& operator=(Quote &&) noexcept;
		std::string isbn() const { return bookNo; }
		virtual double net_price(std::size_t n) const { return n * price; }
		virtual ~Quote() { std::cout << "~Quote()\n"; };
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

Quote&
Quote::operator=(const Quote &rhs)
{
	std::cout << "Quote& operator=(const Quote &)\n";
	auto newdata = rhs;
	bookNo = rhs.bookNo;
	price = rhs.price;
	return *this;
}

Quote&
Quote::operator=(Quote &&rhs) noexcept
{
	if (this != &rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
	std::cout << "Quote& operator(const Quote &&)\n";
	return *this;
}

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
		Disc_quote(const Disc_quote &dq) : Quote(dq),
				quantity(dq.quantity), discount(dq.discount)
			{ std::cout << "Disc_quote(const Disc_quote &)\n"; } 
		Disc_quote(Disc_quote &&dq) noexcept : Quote(std::move(dq)),
			quantity(dq.quantity), discount(dq.discount)
			{ std::cout << "Disc_quote(Disc_quote &&)\n"; }
		Disc_quote& operator=(const Disc_quote &);
		Disc_quote& operator=(Disc_quote &&) noexcept;
		Disc_quote(const std::string &book, double price,
				std::size_t qty, double disc) :
				   Quote(book, price), quantity(qty), discount(disc) {}
		~Disc_quote() { std::cout << "~Disc_quote()\n"; };
		double net_price(std::size_t) const = 0; // pure virtual function

	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

Disc_quote&
Disc_quote::operator=(const Disc_quote &rhs)
{
	Quote::operator=(rhs);
	// There's no need for guarding against self-assignemnt, for
	// direct initialization, including copy-initialization,
	// of Dis_quote objects is not possible.
	quantity = rhs.quantity;
	discount = rhs.discount;
	std::cout << "Disc_quote& operator=(const Disc_quote &)\n";
	return *this;
}

Disc_quote&
Disc_quote::operator=(Disc_quote &&rhs) noexcept
{
	if (this != &rhs) {    // good practice, but not necessary
		Quote::operator=(std::move(rhs));
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	std::cout << "Disc_quote& operator=(const Disc_quote &&)\n";
	return *this;
}

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq)
			{ std::cout << "Bulk_quote(const Bulk_quote &)\n"; } 
		Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq))
			{ std::cout << "Bulk_quote(Bulk_quote &&)\n"; }
		Bulk_quote& operator=(const Bulk_quote &);
		Bulk_quote& operator=(Bulk_quote &&) noexcept;
		Bulk_quote(const std::string &book, double price,
				std::size_t qty, double disc) :
			Disc_quote(book, price, qty, disc) {}
		~Bulk_quote() { std::cout << "~Bulk_quote()\n"; };
		double net_price(std::size_t) const override;
};

Bulk_quote&
Bulk_quote::operator=(const Bulk_quote &rhs)
{
	Disc_quote::operator=(rhs);
	std::cout << "Bulk_quote& operator=(const Bulk_quote &)\n";
	return *this;
}

Bulk_quote&
Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
	if (this != &rhs)
		Disc_quote::operator=(std::move(rhs));
	std::cout << "Bulk_quote& operator=(const Bulk_quote &&)\n";
	return *this;
}

double
Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	return cnt * price;
}

int main()
{
	Bulk_quote bulk("9-999-99999-9", 34.99, 10, 0.5);
	Bulk_quote bulk2(bulk);
	Bulk_quote bulk3(std::move(bulk));

	Bulk_quote bulk4("3-333-33333-3", 25.49, 2, 0.5);;
	bulk2 = bulk4;
	bulk2 = std::move(bulk4);

	print_total(std::cout, bulk, 10);
	print_total(std::cout, bulk2, 10);
	return 1;
}
