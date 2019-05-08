/*
 * Exercise 10.21: Write a lambda that captures a local int variable and
 * decrements that variable until it reaches 0. Once the variable is 0
 * additional calls should no longer decrement the variable. The lambda should
 * return a bool that indicates whether the captured variable is 0.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	int x{10};
	auto f = [&x] () -> bool
	              { if (x) { --x; return false; } else return true; }; 
	while (!f())
		std::cout << x << '\n';
	return 0;
}
