/*
 * Exercise 3.2: Write a program to read the standard input a line at a time.
 * Modify your program to read a word at a time.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cin; using std::cout; using::getline;
using std::endl; using std::string;

int main() {
//	string line;
//	while (getline(cin, line))
//		cout << line << endl;

	string word;
	while (cin >> word)
		cout << word << endl;
	return 0;
}
