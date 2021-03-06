/*
 * Exercise 3.10: Write a program that reads a string of characters including
 * punctuation and writes what was read but with the punctuation removed.
 *
 * By Faisal Saadatmand
 */

#include <cctype>
#include <iostream>

using std::cout; using std::endl;; using std::string;

int main()
{
	string s("Hello, World!!!\n");
	for (auto c : s)
		if (!ispunct(c))
			cout << c;
	return 0;
}
