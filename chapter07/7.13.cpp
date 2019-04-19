/* 
 * Exercise 7.13: Rewrite the program from page 255 to use the istream constructor.
 *
 * Note: the constructor can be called only once--when the object is created.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data total(std::cin);        // istream constructor is explicitly called
	if (std::cin) {
		Sales_data trans;              // default constructor is implicitly called
		while (read(std::cin, trans)) {
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total);
				std::cout << '\n';
				total = trans;
			}
		}
		print(std::cout, total);
		std::cout << '\n';
	} else {
		std::cerr << "No data?!" << std::endl;
	}
	return 0;
}
