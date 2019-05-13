/*
 * Exercise 11.11: Redefine bookstore without using decltype.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include "Sales_data.h"
#include <set>


bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	std::multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)>
		bookstore(compareIsbn);
	Sales_data book;
	while (read(std::cin, book)) {
		bookstore.insert(book);
	}
	for (const auto &elem : bookstore)
		std::cout << elem.isbn() << '\n';
	return 0;
}
