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

	if (ivec.empty())
		return 1;

	cout << "Vector's elements:";
	for (const auto &i : ivec)
		cout << ' ' << i;
	cout << '\n';

	auto end = ivec.size();
	cout << "Sum of each pair of adjacent elements:";
	for (decltype(ivec.size()) i = 1; i < end; ++i)
		cout << ' ' << ivec[i] + ivec[i - 1];
	cout << '\n';

	cout << "Sum of elements at extreme ends:";
	for (decltype(ivec.size()) i = 0; i < end / 2; ++i)
		cout << ' ' << ivec[i] + ivec[end - 1 - i];
	cout << '\n';

	return 0;
}
