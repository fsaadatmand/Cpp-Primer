/*
 * Exercise 19.13: Define the type that can represent a pointer to the bookNo
 * member of the Sales_data class.
 *
 * By Faisal Saadatmand
 */

/*
 * Note: must add the following member function to Sales_data to return the
 * address of bookNo
 *
 *		 static const std::string Sales_data::* bookNo_data()
 *		 						{ return &Sales_data::bookNo; }
 */

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data item("9-999-99999-9");
	const std::string Sales_data::*pbn = Sales_data::bookNo_data();
	std::cout << item.*pbn << '\n';
	return 0;
}
