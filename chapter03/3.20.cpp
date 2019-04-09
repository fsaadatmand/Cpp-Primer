/*
 * Exercise 3.20: Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements. Change your program so that it prints the sum of
 * the first and last elements, followed by the sum of the second and
 * second-to-last, and so on.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	using std::cin; using std::cout; using std::vector;

	int number;
	vector<int> ivec;

	while (cin >> number)
		ivec.push_back(number);

	cout << "Vector's elements: ";
	for (auto i : ivec)
		cout << i << " ";
	cout << '\n';

	if (!ivec.empty()) {
		cout << "Sum of each pair of adjacent elements: ";
		int end = ivec.size() - 1;
		for (decltype(ivec.size()) i = 0; i < end; i += 2)
			cout << ivec[i] + ivec[i + 1] << " ";
		cout << '\n';
	}

	if (!ivec.empty()) {
		cout << "Sum of extreme ends elements: ";
		int end = ivec.size() - 1;
		for (decltype(ivec.size()) i = 0; i <= end / 2; ++i)
			cout << ivec[i] + ivec[end - i] << " ";
		cout << '\n';
	}
	return 0;
}
