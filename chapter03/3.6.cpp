/*
 * Exercise 3.6: Use a range for to change all the characters in a string to X.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cout; using std::endl; using std::string;

int main()
{
	string str = "change me";

	for (auto &c : str)
		c = 'X';
	cout << str << endl;

	return 0;
}


