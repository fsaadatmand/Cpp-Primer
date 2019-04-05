/* 
 * Exercise 2.40: Write your own version of the Sales_data class.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned int units_solds = 0;
	double revenue = 0.0;
};
