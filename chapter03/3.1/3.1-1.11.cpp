/*
 * Exercise 3.1: Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76)
 * with appropriate using declarations.
 *
 * Exercise 1.11: Write a program that prompts the user for two integers. Print
 * each number in the range specified by those two integers.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
	int start, end;

	cout << "Enter to integers to print numbers within range: ";
	cin >> start >> end;
	while (start <= end)
		cout << start++ << " ";
	cout << endl;
	return 0;
}
