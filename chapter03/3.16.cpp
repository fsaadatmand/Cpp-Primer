/*
 * Exercise 3.16: Write a program to print the size and contents of the vectors
 * from exercise 3.13. Check whether your answers to that exercise were
 * correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were
 * wrong.
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


	cout << "v1:\n" 
		 << "size " << v1.size() << '\n';
	if (!v1.empty()) {
		cout << "value ";
		for (auto x : v1)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	cout << "v2:\n" 
		 << "size " << v2.size() << '\n';
	if (!v2.empty()) {
		cout << "value ";
		for (auto x : v2)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	cout << "v3:\n" 
		 << "size " << v3.size() << '\n';
	if (!v3.empty()) {
		cout << "value ";
		for (auto x : v3)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	cout << "v4:\n" 
		 << "size " << v4.size() << '\n';
	if (!v4.empty()) {
		cout << "value ";
		for (auto x : v4)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	cout << "v5:\n" 
		 << "size " << v5.size() << '\n';
	if (!v5.empty()) {
		cout << "value ";
		for (auto x : v5)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	cout << "v6:\n" 
		 << "size " << v6.size() << '\n';
	if (!v6.empty()) {
		cout << "value ";
		for (auto x : v6)
			cout << x << " ";
		cout << "\n\n";
	} else
		cout << "value: empty vector\n\n";

	return 0;
}
