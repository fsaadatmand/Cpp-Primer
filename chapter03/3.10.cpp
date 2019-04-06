/*
 * Exercise 3.10: Write a program that reads a string of characters including
 * punctuation and writes what was read but with the punctuation removed.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cout; using std::endl;; using std::string;

int main()
{
	string s("Hello World!!!");
	for (auto c : s)
		if (!ispunct(c))     // defined in std namespace. cctype is not needed
			cout << c;
	cout << endl;
	return 0;
}
