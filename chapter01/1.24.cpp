/*
 * Exercise 1.24: Test the previous program by giving multiple transactions
 * representing multiple ISBNs. The records for each ISBN should be grouped
 * together.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	int count1, count2, count3;
	Sales_item item1, item2, item3, isbnGroup1, isbnGroup2, isbnGroup3;

	std::cout << "Enter 3 transactions:" << std::endl;
	std::cin >> item1 >> item2 >> item3;
	count1 = count2 = count3 = 0;
	isbnGroup1 = item1;
	count1++;
	if (item2.isbn() == isbnGroup1.isbn()) {
		isbnGroup1 += item2;
		count1++;
	} else {
		isbnGroup2 = item2;
		count2++;
	}

	if (item3.isbn() == isbnGroup1.isbn()) {
		isbnGroup1 += item3;
		count1++;
	} else if (item3.isbn() == isbnGroup2.isbn()) {
		isbnGroup2 += item3;
		count2++;
	} else {
		isbnGroup3 = item3;
		count3++;
	}

	if (count1)
		std::cout << isbnGroup1 << std::endl;
	if (count2)
		std::cout << isbnGroup2 << std::endl;
	if (count3)
		std::cout << isbnGroup3 << std::endl;
	return 0;
}
