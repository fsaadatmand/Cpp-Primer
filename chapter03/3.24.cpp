/*
 * Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.
 *
 * by Faisal Saadatmand
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

	cout << "Vector's elements:";
	for (auto i : ivec)
		cout << ' ' << i;
	cout << '\n';

	if (ivec.empty())
		return 1;

	cout << "Sum of each pair of adjacent elements:";
	for (auto it = ivec.cbegin() + 1; it != ivec.cend(); ++it)
		cout << ' ' << *it + *(it - 1);
	cout << '\n';

	cout << "Sum of extreme ends elements:";
	auto beg = ivec.cbegin(), end = ivec.cend() - 1;
	while (beg < end)
		cout << ' ' << *beg++ + *end--;
	cout << '\n';

	return 0;
}
