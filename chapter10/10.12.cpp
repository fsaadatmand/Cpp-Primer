/*
 * Exercise 10.12: Write a function named compareIsbn that compares the isbn()
 * members of two Sales_data objects. Use that function to sort a vector that
 * holds Sales_data objects.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Sales_data.h"

bool compareIsbn(const Sales_data &item1, const Sales_data &item2)
{
	return item1.isbn() < item2.isbn();
}

int main()
{
	std::vector<Sales_data> books{{"9-999-99999-9"}, {"1-111-11111-1"},
		{"4-444-44444-4"}, {"7-777-77777-7"}, {"3-333-33333-3"}, {"5-555-55555-5"}};
	sort(books.begin(), books.end(), compareIsbn);
	for (auto const &book : books)
		print(std::cout, book);
	std::cout << '\n';
	return 0;
}
