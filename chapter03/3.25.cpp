/*
 * Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
 * using iterators instead of subscripts.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	using std::cin; using std::cout; using std::vector;
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0
	unsigned grade;
	auto it = scores.begin();
	while (cin >> grade) 
		if (grade <= 100)
			*(it + (grade/10)) += 1;
	for (auto i : scores)
		cout << i << " ";
	cout << '\n';
	return 0;
}
