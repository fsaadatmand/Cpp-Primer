/*
 * Exercise 17.36: Modify the program from the previous exercise to print the
 * various floating-point values so that they line up in a column.
 *
 * By Faisal Saadatmand
 */

#include <cmath>
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::left << std::setw(20) << "default format: "
		<< std::right << std::setw(30) << 100 * sqrt(2.0) << '\n'
		<< std::left << std::setw(20) << "scientific: "
		<< std::right << std::setw(30) << std::scientific << 100 * sqrt(2.0) << '\n'
		<< std:: left << std::setw(20) << "fixed decimal: "
		<< std::fixed << std::right << std::setw(30) << 100 * sqrt(2.0) << '\n'
		<< std::left << std::setw(20) << "hexadecimal: "
		<< std::hexfloat << std::uppercase
		<< std::right << std::setw(30) << 100 * sqrt(2.0) << '\n'
		<< std::defaultfloat << std::nouppercase;
	return 0;
}
