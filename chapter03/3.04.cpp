/*
 * Exercise 3.4: Write a program to read two strings and report whether the
 * strings are equal. If not, report which of the two is larger. Now, change
 * the program to report whether the strings have the same length, and if not,
 * report which is longer.

 * By Faisal Saadatmand
 */

#include <iostream>

using std::cin; using std::cout;
using std::endl; using std::string;

int main() {
	string s1, s2;

	cin >> s1 >> s2;
/*
	if (s1 == s2)
		cout << "equal" << endl;
	else if (s1 > s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;
*/
	if (s1.size() == s2.size())
		cout << "equal lengths" << endl;
	else if (s1.size() > s2.size())
		cout << s1 << endl;
	else
		cout << s2 << endl;
	return 0;
}
