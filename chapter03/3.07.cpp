/*
 * Exercise 3.7: What would happen if you define the loop control variable in
 * the previous exercise as type char? Predict the results and then change your
 * program to use a char to see if you were right.
 * 
 * By Faisal Saadatmand
 */

/*
 * Answer: the loop would not be able to change the characters in the string
 * because c would be a copy of the string's character. We must use a reference
 * to a char (char &) to change the elements of a string.
 */

#include <iostream>

using std::cout; using std::endl; using std::string;

int main()
{
	string str = "change me";
	for (char c : str)
		c = 'X';
	cout << str << endl;
	return 0;
}
