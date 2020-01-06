/*
 * Exercise 3.8: Rewrite the program in the first exercise, first using a while
 * and again using a traditional for loop. Which of the three approaches do you
 * prefer and why?
 *
*
 * By Faisal Saadatmand
 */

/*
 * Answer: coming from C, I prefer less abstractions. However, it is nice to
 * have the convenience and the improved security and readability of the range
 * for loop. Therefore, it makes more sense to use it whenever appropriate over
 * the other two methods.
 */
 
#include <iostream>

using std::cout; using std::endl; using std::string;

int main()
{
	string str = "while loop";
	decltype(str.size()) index = 0;
	while (index < str.size())
		str[index++] = 'X';
	cout << str << endl;

	for (decltype(str.size()) i = 0; i < str.size(); ++i)
		str[i] = 'O';
	cout << str << endl;
	return 0;
}
