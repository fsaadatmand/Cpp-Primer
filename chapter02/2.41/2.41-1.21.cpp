/*
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

struct Sales_data {
	std::string bookNo;
	unsigned unites_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data item1, item2;

	double price = 0;
	std::cin >> item1.bookNo >> item1.unites_sold >> price;
	item1.revenue = item1.unites_sold * price;
	std::cin >> item2.bookNo >> item2.unites_sold >> price;
	item2.revenue = item2.unites_sold * price;

	if (item1.bookNo != item2.bookNo) {
		std::cerr << "ISBN mismatch" << std::endl;
		return -1;
	}

	unsigned totalCount = item1.unites_sold + item2.unites_sold;
	double totalRevenue = item1.revenue + item2.revenue;
	std::cout << item1.bookNo << " " << totalCount << " " 
		      << totalRevenue << std::endl;

	if (totalCount != 0)
		std::cout << totalRevenue/totalCount << std::endl;
	else
		std::cout << "(no sales)" << std::endl;

	return 0;
}
