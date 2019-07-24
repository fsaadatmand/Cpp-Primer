/*
 * Exercise 17.31: What would happen if we defined b and e inside the do loop
 * of the game-playing program from this section?
 *
 * By Faisal Saadatmand
 */

// Note: the examples are taken from the textbook.

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <cstdio>

bool get_status()
{
	static std::default_random_engine e(time(0));
	static std::bernoulli_distribution u;
	return u(e);
}

int main()
{
	std::cout << std::boolalpha << get_status() << std::noboolalpha << '\n';
	
	std::cout << std::showbase
			  << "default: " << 20 << ' '
			  << "in octal: " << std::oct << 20 << ' ' << 1204 << '\n'
			  << "in hex: " << std::hex << 20 << ' ' << 1204 << '\n'
			  << "in decimal: " << std::dec << 20 << ' ' << 1204 << "\n\n"
			  << std::noshowbase;

	std::cout << std::uppercase << std::showbase << std::hex
			  << "printed in hexadecimal: " << 20 << ' ' << 1024
			  << std::nouppercase << std::noshowbase << std::dec << "\n\n";

	// cout.precision reports the current precision value
	std::cout << "Precision: " << std::cout.precision()
			  << ", Value: " << sqrt(2.0) << '\n';
	// cout.precision(12) asks that 12 digits of precision be printed
	std::cout.precision(12);
	std::cout << "Precision: " << std::cout.precision()
			  << ", Value: " << sqrt(2.0) << '\n';
	// alternative way to set precision using the setprecision manipulator
	std::cout << std::setprecision(3);
	std::cout << "Precision: " << std::cout.precision()
			  << ", Value: " << sqrt(2.0) << "\n\n";

	std::cout << "default format: " << 100 * sqrt(2.0) << '\n'
			  << "scientific: " << std::scientific << 100 * sqrt(2.0) << '\n'
			  << "fixed decimal: " << std::fixed << 100 * sqrt(2.0) << '\n'
			  << "hexadecimal: " << std::hexfloat << 100 * sqrt(2.0) << '\n'
			  << "use defaults: " << std::defaultfloat << 100 * sqrt(2.0)
			  << "\n\n";

	std::cout << 10.0 << '\n';
	std::cout << std::showpoint << 10.0
			  << std::noshowpoint << "\n\n";

	int i = -16;
	double d = 3.14159;
	// pad the first column to use a minimum of 12 positions in the output
	std::cout << "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column and left-justify all columns
	std::cout << std::left
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n'
		<< std::right;
	// restore normal justification
	// pad the first column and right-justify all columns
	std::cout << std::right
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column but put the padding internal to the field
	std::cout << std::internal
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';
	// pad the first column, using # as the pad character
	std::cout << std::setfill('#')
		<< "i: " << std::setw(12) << i << "next col" << '\n'
		<< "d: " << std::setw(12) << d << "next col" << '\n';

	std::cout << "a string" << std::endl;
	std::cout << "a string\n" << std::flush;
	
	std::stringstream oss;
    oss << "Sample text: " << 42 << std::ends;
	std::cout << oss.str() << '\n';

	std::cout << "Enter text to illustrate noskipws: ";
	char ch;
	std::cin >> std::noskipws;
	while (std::cin >> ch)
		std::cout << ch;
	std::cin >> std::skipws;
	return 0;
}
