/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with approriate using declarations.
 *
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

using std::cin; using std::cout; using std::cerr;
using  std::endl; using std::string;

struct Sales_data {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data items, newItem;
	double price = 0.0;
	int transCount = 0;

	if (!(cin >> items.bookNo >> items.units_sold >> price)) {
		cerr << "Invalid data";
		return -1;
	}
	++transCount;
	while (cin >>	newItem.bookNo >> newItem.units_sold >> price) {
		if (newItem.bookNo != items.bookNo) {
			cerr << "ISBN mismatch" << endl;
			return -1;
		}
		++transCount;
	}
	cout << "Number of transactions: " << transCount << endl;
	return 0;
}
