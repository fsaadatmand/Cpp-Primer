/*
 * Exercise 12.16: Compilers don’t always give easy-to-understand error
 * messages if we attempt to copy or assign a unique_ptr. Write a program that
 * contains these errors to see how your compiler diagnoses them.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> p1(new int(41));
	std::cout << *p1 << '\n';
	std::unique_ptr<int> p2(p1);
	std::unique_ptr<int> p3;
	p3 = p2;
	return 0;
}
