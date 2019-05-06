/*
 * Exercise 9.50: Write a program to process a vector<string>s whose elements
 * represent integral values. Produce the sum of all the elements in that
 * vector. Change the program so that it sums of strings that represent
 * floating-point values.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> svec{"55", "34", "52", "8", "12", "25", "43"};
	int isum = 0;
	for (auto &element : svec)
		isum += stoi(element);
	std::cout << isum << '\n';

	double dsum = 0;
	std::vector<std::string> svec2{"55.5", "34.3", "52.99", "8.3", "12",
		                           "25", "43.41"};
	for (auto &element : svec2)
		dsum += stod(element);
	std::cout << dsum << '\n';
	return 0;
}
