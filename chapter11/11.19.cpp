/*
 * Exercise 11.19: Define a variable that you initialize by calling begin() on
 * the multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s
 * type without using auto or decltype.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <set>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	std::multiset<Sales_data, decltype(compareIsbn) *> bookstrore(compareIsbn);

	// using auto
	auto iter_1 = bookstrore.cbegin();

	// not using auto
	std::multiset<Sales_data, decltype(compareIsbn) *>::const_iterator
		iter_2 = bookstrore.cbegin();

	// using neither auto nor decltype
	std::multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
		::const_iterator iter_3 = bookstrore.cbegin();

	return 0;
}
