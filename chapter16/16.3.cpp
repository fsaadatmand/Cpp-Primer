/*
 * Exercise 16.3: Call your compare function on two Sales_data objects to see
 * how your compiler handles errors during instantiation.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <functional>
#include "Sales_data.h"

template <typename T>
int compare (const T &v1, const T &v2)
{
	if (std::less<T>()(v1, v2)) return -1;
	if (std::less<T>()(v2, v1)) return 1;
	return 0;
}

int main()
{
	Sales_data a("1-111-11111-1");
	Sales_data b("2-222-22222-2");
	Sales_data c("3-333-33333-3");

	std::cout << compare(a, b) << '\n';
	std::cout << compare(b, b) << '\n';
	std::cout << compare(a, c) << '\n';
	return 0;
}
