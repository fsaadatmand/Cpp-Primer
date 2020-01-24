/*
 * Exercise 8.8: Revise the program from the previous exercise to append its
 * output to its given file. Run the program on the same output file at least
 * twice to ensure that the data are preserved.
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

	if (--argc != 2) {
		std::cerr << "Usage: " + std::string(*argv)
			         + " <input_file> <output_file>\n";
		return -1;
	}

	auto p = argv + 1;
	std::ifstream input(*p);
	if (!input) {
		std::cerr << "Couldn't open " << *p << '\n';
		return -1;
	}

	std::ofstream output(*++p, std::ofstream::app);  
	if (!output) {
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
				output << total.bookNo << " "
					<< total.units_sold << " "
					<< total.revenue << " "
					<< averagePrice << std::endl;
				total = trans;
			}
		}
		output << total.bookNo << " "
			<< total.units_sold << " "
			<< total.revenue << " "
			<< averagePrice << std::endl;
	} else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
