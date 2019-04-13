/*
 * Exercise 5.14: Write a program to read strings from standard input looking
 * for duplicated words. The program should find places in the input where one
 * word is followed immediately by itself. Keep track of the largest number of
 * times a single repetition occurs and which word is repeated. Print the
 * maximum number of duplicates, or else print a message saying that no word
 * was repeated. For example, if the input is
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> words;
	std::string str;

	while (std::cin >> str)
		words.push_back(str);

	unsigned count = 1, largestCount = 0;
	auto it = words.begin(), wordIndex = it;
		while (it != words.end()) {
		// bounds check before dereferencing the next element in words
			if (it + 1 != words.end() && *it == *(it + 1))
				++count;
			else {
				if (count > largestCount) {
					largestCount = count;
					wordIndex = it;
				}
				count = 1;             // starting a new word
			}
			++it;
		}

	if (largestCount > 1)
		std::cout << *wordIndex << " occurred " 
			      << largestCount << " times\n";
	else
		std::cout << "no word was repeated\n";

	return 0;
}
