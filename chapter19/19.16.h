/*
 * Exercise 19.16: Write a type alias that is a synonym for a pointer that can
 * point to the avg_price member of Sales_data.
 *
 * By Faisal Saadatmand
 */

/* 
 * The Alias is defined in Sales_data.h as:
 *
 *		 using Average_fmp = double (Sales_data::*)() const;
 * 
 * Since avg_price is a private function member, we define a public function to
 * return a pointer to it. See Sales_data.h for get_average_fmp().
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	// input some data
	Sales_data item("1-111-11111-1", 10, 25.99);
	Sales_data item2("1-111-11111-1", 10, 15.99);
	// process the data
	auto item3 = item + item2;
	// point to avg_price()
	// get_average_fmp returns a member function pointer
	auto avg_fmp = item3.get_average_fmp();
	// fetch avg_price
	std::cout << (item3.*avg_fmp)() << '\n';
	return 0;
}
