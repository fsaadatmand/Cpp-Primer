/*
 * Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read
 * its transactions from a file. Pass the name of the file as an argument to
 * main (§ 6.2.5, p. 218).
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main(int argc, char **argv)
{
	Sales_data total;
	double averagePrice = 0.0;
	double price = 0.0;

	if (--argc != 1) {
		std::cerr << "Usage: " + std::string(*argv) + " <filename>\n";
		return -1;
	}
	auto p = argv + 1;
	std::ifstream input(*p);
	if (!input) {
		std::cerr << "Couldn't open " << *p << '\n';
		return -1;
	}
	if (input >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (input >> trans.bookNo >> trans.units_sold >> price) {
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
				averagePrice = total.revenue / total.units_sold;
			} else {
				std::cout << total.bookNo << " "
					<< total.units_sold << " "
					<< total.revenue << " "
					<< averagePrice << std::endl;
				total = trans;
			}
		}
		std::cout << total.bookNo << " "
			<< total.units_sold << " "
			<< total.revenue << " "
			<< averagePrice << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
