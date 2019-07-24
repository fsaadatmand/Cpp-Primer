/*
 * Exercise 17.35: Write a version of the program from page 758, that printed
 * the square root of 2 but this time print hexadecimal digits in uppercase.
 *
 * By Faisal Saadatmand
 */

#include <cmath>
#include <iostream>

int main()
{
	std::cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << std::scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << '\n'
		<< "hexadecimal: " << std::hexfloat << std::uppercase
		<< 100 * sqrt(2.0) << '\n'
		<< std::defaultfloat << std::nouppercase;
	return 0;
}
