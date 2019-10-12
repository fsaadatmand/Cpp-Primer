/*
 * Exercise 15.6: Test your print_total function from the exercises in § 15.2.1
 * (p. 595) by passing both Quote and Bulk_quote objects o that function.
 *
 * By Faisal Saadatmand
 */

#include "15.05.h" // Bulk_quote

int main()
{
	Quote item1("1-111-11111-1", 25);
	Bulk_quote item2("2-222-22222-2", 25, 5, 0.25);
	print_total(std::cout, item1, 10); // full price
	print_total(std::cout, item2, 10); // discounted
	return 0;
}
