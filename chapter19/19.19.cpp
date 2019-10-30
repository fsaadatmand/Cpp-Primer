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

void sort_vector(std::vector<Sales_data> &items)
{
	std::sort(items.begin(), items.end(),
			[](Sales_data &item1, Sales_data item2) {
			auto f1 = std::mem_fn(item1.get_average_fmp());
			auto f2 = std::mem_fn(item2.get_average_fmp());
			return f1(item1) < f2(item2);
			});
}

Sales_data average_price_is_greater_than(const std::vector<Sales_data> &items,
										 const double n)
{
	auto it = std::find_if(items.cbegin(), items.end(),
			[&n](const Sales_data &item)
			{ return std::mem_fn(item.get_average_fmp())(item) > n; });
	if (it != items.end())
		return *it;
	return Sales_data();
}

int main()
{
	std::vector<Sales_data> books{ {"1-111-11111-1", 10, 15.59},
								   {"2-222-22222-2", 10, 24.05},
								   {"3-333-33333-3", 10, 26.95},
								   {"4-444-44444-4", 10, 19.99},
								   {"5-555-55555-5", 10, 35.50}
								 };
	constexpr double average_price = 19;
	sort_vector(books); // sorting is required for accuracy
	Sales_data book = average_price_is_greater_than(books, average_price);
	if (book != Sales_data())
		std:: cout << book << '\n';
	return 0;
}
