/*
 * Exercise 3.17: Read a sequence of words from cin and store the values in a
 * vector. After you’ve read all the words, process the vector and change each
 * word to uppercase.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	using std::cin; using std::cout;
	using std::string; using std::vector;

	vector<string> vec1;
	string word;
	while (cin >> word)
		vec1.push_back(word);
	for (decltype(vec1.size()) ix = 0; ix < vec1.size(); ++ix) {
		for (char &i : vec1[ix])
			i = toupper(i);
		cout << ' ' << vec1[ix];
	}
	cout << '\n';
	return 0;
}
