/*
 * Exercise 17.6: Rewrite findBook so that it does not use tuple or pair.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include "Sales_data.h"

// matches has three members: an index of a store and iterators
// into that store's vector
struct Result {
	std::vector<Sales_data>::size_type index;
	std::vector<Sales_data>::const_iterator first;
	std::vector<Sales_data>::const_iterator last;
};

// files holds the transactions for every store
// findBook returns the transactions for every store
	std::vector<Result>
findBook(const std::vector<std::vector<Sales_data>> &files,
		const std::string &book)
{
	std::vector<Result> ret; // initially empty
	// for each store find the range of matching books, if any
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		// find the of Sales_data that have the same ISBN
		auto found = std::equal_range(it->cbegin(), it->cend(),
				book, compareIsbn);
		if (found.first != found.second) { // this store had sales
			// remember the index of this store and the matching range
			Result matches;
			matches.index = it - files.cbegin();
			matches.first = found.first;
			matches.last = found.second;
			ret.push_back(matches);
		}
	}
	return ret; // empty if no matches found
}

void reportResults(std::istream &in, std::ostream &os,
		const std::vector<std::vector<Sales_data>> files)
{
	std::string s; // book to look for
	while (in >> s) {
		auto trans = findBook(files, s); // stores that sold this book
		if (trans.empty()) {
			std::cout << s << " not found in any stores\n";
			continue; // get the next book to look for
		}
		for (const auto &store : trans) // for every store with a sale
			// get<n> returns the specified member from the tuple in store
			os << "store " << store.index << " sales: "
			   << std::accumulate(store.first, store.last,
								  Sales_data(s)) << '\n';
	}
}

std::vector<Sales_data> loadFile(std::ifstream &infile)
{
	std::vector<Sales_data> file;
	Sales_data book;
	while (infile >> book)
		file.emplace_back(book);
	return file;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << *argv <<
			" <filename(1)>...<filename(2)>...<filename(n)\n";
		return -1;
	}
	std::vector<std::vector<Sales_data>> sales;
	while (--argc > 0) {
		std::ifstream infile(*++argv);
		if (!infile) {
			std::cerr << "Cannot open " << *argv << '\n';
			return -1;
		}
		sales.emplace_back(loadFile(infile)); // build vector<vector<Sales_data>>
	}
	reportResults(std::cin, std::cout, sales);
	return 0;
}
