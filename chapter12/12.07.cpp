/*
 * Exercise 12.7: Redo the previous exercise, this time using shared_ptr.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

auto allocVector()
{
	return std::make_shared<std::vector<int>>();
}

void fillVector(std::istream &is, std::shared_ptr<std::vector<int>> &pv)
{
	int i;
	while (is >> i)
		pv->push_back(i);
}

void printVector(std::ostream &os, const std::shared_ptr<std::vector<int>> &pv)
{
	for (auto &elem : *pv)
		os << elem << ' ';
}

int main()
{
	auto p = allocVector();
	fillVector(std::cin, p);  
	printVector(std::cout, p);
	std::cout << std::endl;
	return 0;
}
