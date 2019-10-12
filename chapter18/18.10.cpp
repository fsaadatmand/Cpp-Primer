/*
 * Exercise 18.10: Write a program that uses the Sales_data addition operator
 * on objects that have differing ISBNs. Write two versions of the program: one
 * that handles the exception and one that does not. Compare the behavior of
 * the programs so that you become familiar with what happens when an uncaught
 * exception occurs.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "18.09.h" // Sales_data

int main()
{
	Sales_data item1("1-111-11111-1", 25, 2);
	Sales_data item2("2-222-22222-2", 15, 3);
	try {
	std::cout << item1 + item2 << '\n';
	} catch (const isbn_mismatch &e) {
		std::cerr << e.what() << ": left isbn(" << e.left
				  << ") right isbn(" << e.right << ")" << std::endl;
	}
	return 0;
}
