/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with appropriate using declarations.
 *
 * Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
 * (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
 * Sales_data class in the same file as your main function.
 *
 * Exercise 1.23: Write a program that reads several transactions and counts
 * how many transactions occur for each ISBN.
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
	Sales_data currItem, item;
	double price = 0.0;
	int transCount = 0;

	cout << "Enter transactions:" << endl;
	if (!(cin >> currItem.bookNo >> currItem.units_sold >> price)) {
		cerr << "Ivalid data" << endl;;
		return -1;
	}
	++transCount;
	while (cin >> item.bookNo >> item.units_sold >> price)
		if (currItem.bookNo == item.bookNo)
			transCount++;
		else {
			cout << currItem.bookNo << " " << transCount <<  endl;
			currItem = item;
			transCount = 1;
		}
	cout << currItem.bookNo << " " << transCount << endl;
	return 0;
}
