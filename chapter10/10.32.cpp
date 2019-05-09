/*
 * Exercise 10.32: Rewrite the bookstore problem from § 1.6 (p. 24) using a
 * vector to hold the transactions and various algorithms to do the processing.
 * Use sort with your compareIsbn function from § 10.3.1 (p. 387) to arrange
 * the transactions in order, and then use find and accumulate to do the sum.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <numeric>
#include <vector>
#include "Sales_item.h"

bool compareIsbd(const Sales_item &item1, const Sales_item &item2)
{
	return item1.isbn() <= item2.isbn();
}

int main()
{
	// iostream iterators
	std::istream_iterator<Sales_item> in_iter(std::cin), eof;
	std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");
	// initialize vector of transaction from istream iterator
	std::vector<Sales_item> trans(in_iter, eof); 
	// Note the use of in_iter == eof instead of iter != eof, because cin
	// resets the stream to a valid state when it encountered the end-of-file
	// character but not an error.(Chapter 8) Remmeber that eof is just an
	// iterator (object) that it is a default initialized to 0. (p.404)
	if (in_iter == eof) {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	// sort data in vector
	sort(trans.begin(), trans.end(), compareIsbd);
	// parse unique isbns
	std::vector<Sales_item> isbns;
	unique_copy(trans.cbegin(), trans.cend(), back_inserter(isbns),
			[](const Sales_item &a, const Sales_item &b)
			   { return a.isbn() == b.isbn(); });
	//  print sum of transaction for each unique isbn
	for (auto item = isbns.cbegin(); item != isbns.cend(); ++item) {
		auto start = find(trans.cbegin(), trans.cend(), *item);
		auto end = (item + 1 != isbns.cend()) ? 
			find(trans.cbegin(), trans.cend(), *(item + 1)) : trans.cend();
		out_iter = accumulate(start, end, Sales_item(item->isbn()));
	}
	return 0;
}
