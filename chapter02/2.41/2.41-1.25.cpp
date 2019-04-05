/*
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

struct Sales_data {
	std::string bookNo;
	unsigned unites_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data total;        // variable to hold data for the next transaction
	double price = 0, averagePrice = 0;

	if (std::cin >> total.bookNo >> total.unites_sold >> price) { //read first trans
		total.revenue = total.unites_sold * price;
		Sales_data trans;    // variable to hold the running sum;
		while (std::cin >> trans.bookNo >> trans.unites_sold >> price) {
			trans.revenue = trans.unites_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.unites_sold += trans.unites_sold;
				total.revenue += trans.revenue;
			} else {
				averagePrice = total.revenue / total.unites_sold;
				std::cout << total.bookNo << " "
					      << total.unites_sold << " "
					      << total.revenue << " "
					      << averagePrice << std::endl;  // print previous book result
				total.bookNo = trans.bookNo;
				total.unites_sold = trans.unites_sold;
				total.revenue = trans.revenue;
			}
		}
		averagePrice = total.revenue / total.unites_sold;
		std::cout << total.bookNo << " " 
			      << total.unites_sold << " "
				  << total.revenue << " " 
				  << averagePrice << std::endl;   // print the last transaction
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
