/*
 * Exercise 3.14: Write a program to read a sequence of ints from cin and store
 * those values in a vector.
 *
 * By Faisal Saadatamnd
 */

#include <iostream>
#include <vector>

int main()
{
	using std::cin; using std::cout; using std::vector;

	vector<int> ivec;
	int digit;

	cout << "Enter 5 digts to store in a vector: ";
	for (int i = 0; i < 5; i++) {
		cin >> digit;
		ivec.push_back(digit);
	}

	for (auto i : ivec)
		cout << i << " ";
	cout << '\n';

	return 0;
}
