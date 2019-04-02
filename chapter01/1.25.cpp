#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total;        // variable to hod data for the next transaction

	if (std::cin >> total) { //read first trans
		Sales_item trans;    // variable to hold the running sum;
		while (std::cin >> trans) {  // read and process the rest
			if (total.isbn() == trans.isbn())
				total+= trans;   // update thr running total
			else {
				std::cout << total << std::endl;  // print previous book result
				total = trans;   // trans now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
