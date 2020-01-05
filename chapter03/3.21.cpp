/*
 * Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	using std::vector; using std::string; using std::cout;

	vector<int> v1;
	cout << "v1\n" 
		<< "size: " << v1.size() << '\n'
		<< "value(s):";
	for (auto it = v1.cbegin(); it != v1.cend(); ++it) 
		cout << ' ' << *it;
	cout << '\n';

	vector<int> v2(10);
	cout << "\nv2\n" 
		<< "size " << v2.size() << "\n"
		<< "value ";
	for (auto it = v2.cbegin(); it != v2.cend(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	vector<int> v3(10, 42);
	cout << "\nv3\n" 
		<< "size: " << v3.size() << "\n"
		<< "value(s):";
	for (auto it = v3.cbegin(); it != v3.cend(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	vector<int> v4{10};
	cout << "\nv4\n" 
		<< "size: " << v4.size() << "\n"
		<< "value(s):";
	for (auto it = v4.cbegin(); it != v4.cend(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	vector<int> v5{10, 42};
	cout << "\nv5\n" 
		<< "size: " << v5.size() << "\n"
		<< "value(s):";
	for (auto it = v5.cbegin(); it != v5.cend(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	vector<string> v6{10};
	cout << "\nv6\n" 
		<< "size: " << v6.size() << "\n"
		<< "value(s):";
	for (auto it = v6.cbegin(); it != v6.cend(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	return 0;
}
