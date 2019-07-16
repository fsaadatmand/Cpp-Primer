/*
 * Exercise 16.62: Define your own version of hash<Sales_data> and define an
 * unordered_multiset of Sales_data objects. Put several transactions into the
 * container and print its contents.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"
#include <unordered_set>

namespace std {
template <> struct hash<Sales_data>
{
	using result = size_t;
	using argument_type = Sales_data;
	size_t operator()(const Sales_data&) const;
};
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<std::string>()(s.bookNo) ^
		   hash<unsigned>()(s.units_sold) ^
		   hash<double>()(s.revenue);
}
}

int main() {
	Sales_data item1("9-999-99999-9", 3, 29.99), item2("2-222-22222-2", 6, 23.33);
	std::unordered_multiset<Sales_data> SDset;
	SDset.insert(item1);
	SDset.insert(item2);
	auto pos = SDset.find(item2);
	if (pos != SDset.end())
		std::cout << *pos << '\n';
	else
		std::cout << "not found\n";
	return 0;
}
