/*
 * Exercise 3.15: Repeat the previous program but read strings this time.
 *
 * By Faisal Saadatamnd
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	using std::cin; using std::cout; using std::string; using std::vector;

	vector<string> ivec;
	string word;

	cout << "Enter 5 words to store in a vector: ";
	for (int i = 0; i < 5; i++) {
		cin >> word;
		ivec.push_back(word);
	}

	for (auto s : ivec)
		cout << s << " ";
	cout << '\n';

	return 0;
}
