/*
 * Exercise 3.7: What would happen if you define the loop control variable in
 * the previous exercise as type char? Predict the results and then change your
 * program to use a char to see if you were right.
 * 
 * Answer: the loop would work just the same, because auto deduces type char
 * from the string characters' type.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cout; using std::endl; using std::string;

int main()
{
	string str = "change me";

	for (char &c : str)
		c = 'X';
	cout << str << endl;

	return 0;
}


