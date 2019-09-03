/*
 * Exercise 8.1: Write a function that takes and returns an istream&.  The
 * function should read the stream until it hits end-of-file. The function
 * should print what it reads to the standard output. Reset the stream so that
 * it is valid before returning the stream.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

std::istream &printWords(std::istream &);

std::istream &printWords(std::istream &is)
{
	std::string word;
	while (is >> word)
		std::cout << word << '\n';
	is.clear();
	return is;
}
