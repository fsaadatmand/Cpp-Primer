/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with appropriate using declarations.
 *
 * Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
 * (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
 * Sales_data class in the same file as your main function.
 *
 * Exercise 1.21: Write a program that reads two Sales_item objects that have the
 * same ISBN and produces their sum.
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
	Sales_data item1, item2;

	double price = 0;
	cin >> item1.bookNo >> item1.units_sold >> price;
	item1.revenue = item1.units_sold * price;
	cin >> item2.bookNo >> item2.units_sold >> price;
	item2.revenue = item2.units_sold * price;

	if (item1.bookNo != item2.bookNo) {
		cerr << "ISBN mismatch" << endl;
		return -1;
	}

	unsigned totalCount = item1.units_sold + item2.units_sold;
	double totalRevenue = item1.revenue + item2.revenue;
	cout << item1.bookNo << " " << totalCount << " " 
		      << totalRevenue << endl;

	if (totalCount != 0)
		cout << totalRevenue/totalCount << endl;
	else
		cout << "(no sales)" << endl;

	return 0;
}
