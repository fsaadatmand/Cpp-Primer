/*
* Exercise 4.18: What would happen if the while loop on page 148 that prints
* the elements from a vector used the prefix increment operator?
*
* By Faisal Saadatmand
*/

#include <iostream>
#include <vector>

int main()
{
	using std::cout; using std::endl; using std::vector;
	vector<int> v{20, -4, 9,-2, 43, -10, 8, 21};

	auto pbeg = v.begin(); // print elements up to the first negative value
	while ((pbeg != v.end()) && *pbeg >= 0)
		cout << *pbeg++ << endl; //print the current value and advance pbeg
	return 0;
}
