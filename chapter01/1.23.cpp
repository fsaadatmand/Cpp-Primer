/*
 * Exercise 1.23: Write a program that reads several transactions and counts
 * how many transactions occur for each ISBN.
 *
by Faisal Saadatmand
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	int isbn1, isbn2, isbn3;
	Sales_item item1, item2, item3;

	isbn1 = isbn2 = isbn3 = 0;
	std::cout << "Enter 3 transactions:" << std::endl;
	std::cin >> item1 >> item2 >> item3;
	isbn1++;
	if (item1.isbn() == item2.isbn())
		isbn1++;
	else
		isbn2++;
	if (item1.isbn() == item3.isbn())
		isbn1++;
	else if (item2.isbn() == item3.isbn())
		isbn2++;
	else
		isbn3++;
	std::cout << "ISBN: "  << item1.isbn() << "# trans: "
		<< isbn1 << std::endl;
	std::cout << "ISBN: "  << item2.isbn() << "# trans: "
		<< isbn2 << std::endl;
	std::cout << "ISBN: "  << item3.isbn() << "# trans: "
		<< isbn3 << std::endl;
	return 0;
}
