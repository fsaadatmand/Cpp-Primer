/*
 * Exercise 7.7: Rewrite the transaction-processing program you wrote for the
 * exercises in § 7.1.2 (p. 260) to use these new functions.
 *
 * Note: dependency on Sales_data.c and Sales_data.h
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total;
	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total = add(total, trans);
			} else {
				print(std::cout, total);
				std::cout << '\n';
				total = trans;
			}
		}
		print(std::cout, total);
		std::cout << '\n';
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
