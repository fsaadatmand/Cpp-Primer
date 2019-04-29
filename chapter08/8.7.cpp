/*
 * Exercise 8.7: Revise the bookstore program from the previous section to
 * write its out- put to a file. Pass the name of that file as a second
 * argument to main.
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

	if (argc != 3) {
		std::cerr << "Usage: " + std::string(*argv)
			         + " input_file output_file\n";
		return -1;
	}

	auto p = argv + 1;
	std::ifstream input(*p);
	if (!input) {
		std::cerr << "Couldn't open " << *p << '\n';
		return -1;
	}

	std::ofstream output(*++p);  
	if (!output) {
		std::cerr << "Couldn't open " << *p << '\n';
		return -1;
	}

	if (input >> total.bookNo && input >> total.units_sold && input >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
			while (input >> trans.bookNo && input >> trans.units_sold &&
					input >> price) {
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
