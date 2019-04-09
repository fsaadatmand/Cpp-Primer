/*
 * Exercise 3.22: Revise the loop that printed the first paragraph in text to
 * instead change the elements in text that correspond to the first paragraph
 * to all uppercase. After you’ve updated text, print its contents.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	using std::cout; using std::cin; using std::vector; using std::string;

	vector<string> text;
	string line;

	while (getline(cin, line))
			text.push_back(line);

	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
		for (auto &c : *it)
				c = toupper(c);
		cout << *it << '\n';
	}

return 0;
}
