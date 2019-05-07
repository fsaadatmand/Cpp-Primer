/*
 * Exercise 10.17: Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
 * lambda in the call to sort instead of the compareIsbn function.

 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

int main()
{
	std::vector<Sales_data> books{{"9-999-99999-9"}, {"1-111-11111-1"},
		{"4-444-44444-4"}, {"7-777-77777-7"}, {"3-333-33333-3"}, {"5-555-55555-5"}};
	sort(books.begin(), books.end(),
			[] (const Sales_data &item1, const Sales_data &item2)
			   { return item1.isbn() < item2.isbn(); });
	for (auto const &book : books)
		print(std::cout, book);
	std::cout << '\n';
	return 0;
}
