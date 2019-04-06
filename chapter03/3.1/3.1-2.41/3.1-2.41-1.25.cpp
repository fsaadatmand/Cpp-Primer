/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with appropriate using declarations.
 *
 * Exercise 2.41: Use your Sales_data class to rewrite the exercises in § 1.5.1
 * (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your
 * Sales_data class in the same file as your main function.
 *
 * Exercise 1.25: Using the Sales_item.h header from the Web site, compile and
 * execute the bookstore program presented in this section.
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
	Sales_data total;        // variable to hold data for the next transaction
	double price = 0, averagePrice = 0;

	if (cin >> total.bookNo >> total.units_sold >> price) { //read first trans
		total.revenue = total.units_sold * price;
		Sales_data trans;    // variable to hold the running sum;
		while (cin >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			} else {
				averagePrice = total.revenue / total.units_sold;
				cout << total.bookNo << " "
					      << total.units_sold << " "
					      << total.revenue << " "
					      << averagePrice << endl;  // print previous book result
				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		averagePrice = total.revenue / total.units_sold;
		cout << total.bookNo << " " 
			      << total.units_sold << " "
				  << total.revenue << " " 
				  << averagePrice << endl;   // print the last transaction
	} else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
