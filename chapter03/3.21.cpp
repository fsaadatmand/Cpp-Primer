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
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};


	if (!v1.empty()) {
		cout << "v1\n" 
			 << "size: " << v1.size() << '\n'
			 << "value(s): ";
		for (auto it = v1.cbegin(); it != v1.cend() && *it; it++) 
			cout << *it << " ";
		cout << "\n\n";
	} else
		cout << "v1\nempty\n\n";

	if (!v2.empty()) {
		cout << "v2\n" 
			 << "size " << v2.size() << "\n"
			 << "value ";
		for (auto it = v2.cbegin(); it != v2.cend(); it++)
			cout << *it << " ";
		cout << "\n\n";
	} else
		cout << "v2\nempty\n\n";

	if (!v3.empty()) {
		cout << "v3\n" 
			 << "size: " << v3.size() << "\n"
			 << "value(s): ";
		for (auto it = v3.cbegin(); it != v3.cend(); it++)
			cout << *it << " ";
		cout << "\n\n";
	} else
		cout << "v3\nempty\n\n";

	if (!v4.empty()) {
		cout << "v4\n" 
			 << "size: " << v4.size() << "\n"
			 << "value(s): ";
		for (auto it = v4.cbegin(); it != v4.cend(); it++)
			cout << *it << " ";
		cout << "\n\n";
	} else
		cout << "v4\nempty\n\n";

	if (!v5.empty()) {
		cout << "v5\n" 
			 << "size: " << v5.size() << "\n"
			 << "value(s): ";
		for (auto it = v5.cbegin(); it != v5.cend(); it++)
			cout << *it << " ";
		cout << "\n\n";
	} else
		cout << "v5\nempty\n\n";

	if (!v6.empty()) {
		cout << "v6\n" 
			 << "size: " << v6.size() << "\n"
			 << "value(s): ";
		for (auto it = v6.cbegin(); it != v6.cend(); it++)
			cout << ((it->empty()) ? "empty" :  *it) << " ";
		cout << "\n\n";
	} else
		cout << "v6\nempty\n\n";

	return 0;
}
