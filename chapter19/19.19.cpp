/*
 * Exercise 19.19: Write a function that takes a vector<Sales_data> and finds
 * the first element whose average price is greater than some given amount.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

int main()
{
	std::vector<Sales_data> books{ {"1-111-11111-1", 10, 15.59},
								   {"2-222-22222-2", 10, 24.05},
								   {"3-333-33333-3", 10, 26.95},
								   {"4-444-44444-4", 10, 19.99},
								   {"5-555-55555-5", 10, 35.50}
								 };
	// given average
	const double n = 25;
	// use a lambda instead of bind
	auto AverageisGreater =
		[&n](const Sales_data &item) {
			auto f = std::mem_fn(item.get_average_fmp());
			return f(item) > n;
		};
	auto it = std::find_if(books.cbegin(), books.cend(), AverageisGreater);
	if (it != books.cend())
		std::cout << *it << '\n';
	else
		std::cout << "not found\n";
	return 0;
}
