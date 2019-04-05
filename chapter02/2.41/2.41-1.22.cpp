/*
 * Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
 * (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
 * Sales_data class in the same file as your main function.
 *
 * Exercise 1.22: Write a program that reads several transactions for the same
 * ISBN. Write the sum of all the transactions that were read.
 *
 * By Faisal Saadatmand
*/

#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data items, newItem;
	double price = 0.0;
	int transCount = 0;

	if (!(std::cin >> items.bookNo >> items.units_sold >> price)) {
		std::cerr << "Invalid data";
		return -1;
	}
	++transCount;
	while (std::cin >>	newItem.bookNo >> newItem.units_sold >> price) {
		if (newItem.bookNo != items.bookNo) {
			std::cerr << "ISBN mismatch" << std::endl;
			return -1;
		}
		++transCount;
	}
	std::cout << "Number of transactions: " << transCount << std::endl;
	return 0;
}
