/*
 * Exercise 15.28: Define a vector to hold Quote objects but put Bulk_quote
 * objects into that vector. Compute the total net_price of all the elements in
 * the vector.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "15.27.h" // Quote

int main()
{
	std::vector<Quote> basket;
	basket.push_back(Bulk_quote("2-222-22222-2", 23.45, 2, 0.5));
	basket.push_back(Bulk_quote("1-111-11111-1", 15.99, 1, 0.15));
	basket.push_back(Bulk_quote("3-333-33333-3", 19.99, 4, 0.25));
	basket.push_back(Bulk_quote("2-222-22222-2", 23.45, 2, 0.5));
	basket.push_back(Bulk_quote("4-444-44444-4", 51.50, 20, 0.25));
	basket.push_back(Bulk_quote("1-111-11111-1", 15.99, 1, 0.15));
	basket.push_back(Bulk_quote("2-222-22222-2", 23.45, 2, 0.5));
	basket.push_back(Bulk_quote("1-111-11111-1", 15.99, 1, 0.15));
	basket.push_back(Bulk_quote("3-333-33333-3", 19.99, 4, 0.25));
	basket.push_back(Bulk_quote("2-222-22222-2", 23.45, 2, 0.5));
	basket.push_back(Bulk_quote("9-999-99999-9", 23.45, 2, 0.5));

	sort(basket.begin(), basket.end(),
		[](const Quote &lhs, const Quote &rhs)
			{ return lhs.isbn() < rhs.isbn(); });
	std::size_t n = 0, total = 0;
	for (auto it = basket.cbegin(); it != basket.cend(); it += n) {
		// cout_if will return 1 if the predicate failed
		n = count_if(basket.cbegin(), basket.cend(),
				[&](const Quote &item) { return item.isbn() == it->isbn(); }); 
		total += print_total(std::cout, *it, n);
	}
	std::cout << "\t\t\t\t  Total: " << total << '\n';
	return 0;
}
