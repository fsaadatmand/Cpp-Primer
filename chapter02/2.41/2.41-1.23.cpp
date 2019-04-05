/*
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

struct Sales_data {
	std::string bookNo;
	unsigned unites_sold = 0;
	double revenue = 0.0;
};

int main()
{
	Sales_data currItem, item;
	double price = 0.0;
	int transCount = 0;

	std::cout << "Enter transactions:" << std::endl;
	if (!(std::cin >> currItem.bookNo >> currItem.unites_sold >> price)) {
		std::cerr << "Ivalid data" << std::endl;;
		return -1;
	}
	++transCount;
	while (std::cin >> item.bookNo >> item.unites_sold >> price)
		if (currItem.bookNo == item.bookNo)
			transCount++;
		else {
			std::cout << currItem.bookNo << " " << transCount <<  std::endl;
			currItem = item;
			transCount = 1;
		}
	std::cout << currItem.bookNo << " " << transCount << std::endl;
	return 0;
}
