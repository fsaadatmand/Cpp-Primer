/*
 * Exercise 9.18: Write a program to read a sequence of strings from the
 * standard input into a deque. Use iterators to write a loop to print the
 * elements in the deque.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <deque>

int main()
{
	std::string word;
	std::deque<std::string> dequeOfWords;

	while (std::cin >> word)
		dequeOfWords.push_back(word);
		
	for (auto it = dequeOfWords.cbegin(); it != dequeOfWords.cend(); ++it)
		std::cout << *it << "\n";

	return 0;
}
