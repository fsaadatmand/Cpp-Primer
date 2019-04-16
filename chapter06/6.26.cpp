/*
 * Exercise 6.26: Write a program that accepts the options presented in this
 * section. Print the values of the arguments passed to main.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 0; i < argc; ++i)
		std::cout << "argv[" << i << "] = " << *argv++ << '\n'; 
	return 0;
}
