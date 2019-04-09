/*
 * Exercise 3.23: Write a program to create a vector with ten int elements.
 * Using an iterator, assign each element a value that is twice its current
 * value. Test your program
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	using std::cout; using std::vector;

	vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (auto it = ivec.begin(); it != ivec.end(); ++it) {
		*it *= 2;
		cout << *it << " ";
	}
	cout << '\n';
	return 0;
}
