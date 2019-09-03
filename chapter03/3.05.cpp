/*
 * Exercise 3.5: Write a program to read strings from the standard input,
 * concatenating what is read into one large string. Print the concatenated
 * string. Next, change the program to separate adjacent input strings by a
 * space.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cin; using std::cout;
using std::endl; using std::string;

int main()
{
	string str, output;
	
	while (cin >> str)
		output += str + " ";

	output[output.size() - 1] = '\0'; // delete the trailing space.
	cout << output << endl;

	return 0;
}
