/*
 * Exercise 4.28: Write a program to print the size of each of the built-in
 * types.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	std::cout << "bool\t\t\t" 
		      << sizeof(bool) << '\n';

	std::cout << "char\t\t\t" 
		      << sizeof(char) << '\n';
	std::cout << "unsigned char\t\t" 
		      << sizeof(unsigned char) << '\n';

	std::cout << "wide char\t\t" 
		      << sizeof(wchar_t) << '\n';

	std::cout << "short int\t\t" 
		      << sizeof(short) << '\n';
	std::cout << "unsigned short int\t" 
		      << sizeof(unsigned short) << '\n';

	std::cout << "int\t\t\t" 
		      << sizeof(int) << '\n';
	std::cout << "long int\t\t" 
		      << sizeof(long) << '\n';
	std::cout << "long long int\t\t" 
		      << sizeof(long long) << '\n';

	std::cout << "unsigned int\t\t" 
		      << sizeof(unsigned) << '\n';
	std::cout << "unsigned long int\t" 
		      << sizeof(unsigned long) << '\n';
	std::cout << "unsigned long long int\t" 
		      << sizeof(unsigned long long) << '\n';

	std::cout << "float\t\t\t" 
		      << sizeof(float) << '\n';
	std::cout << "double\t\t\t" 
		      << sizeof(double) << '\n';
	std::cout << "long double\t\t" 
		      << sizeof(long double) << '\n';

	return 0;
}
