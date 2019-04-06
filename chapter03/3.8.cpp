/*
 * Exercise 3.8: Rewrite the program in the first exercise, first using a while
 * and again using a traditional for loop. Which of the three approaches do you
 * prefer and why?
 *
 * Answer: coming from C, I prefer less abstractions. :) However, it is nice to
 * have the convenience and the improved security and readability of the range
 * for loop.  Therefore, it makes more sense to use it whenever is appropriate
 * to do so over the other two methods in C++.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cout; using std::endl; using std::string;

int main()
{
	string str("range for loop");
	for (auto c : str)
		cout << c << endl;

	cout << "\n*\n" << endl;

	string str2 = "while loop";
	decltype(str2.size()) index = 0;
	if (!str2.empty()) {
		while (index < str2.size())
			cout << str2[index++] << endl;
	}

	cout << "\n*\n" << endl;

	string str3 = "traditional for loop";
	if (!str.empty()) {
		for (index = 0; index < str3.size(); index++)
			cout << str3[index] << endl;
	}

	cout << endl;

	return 0;
}
