/*
 * Exercise 5.20: Write a program to read a sequence of strings from the
 * standard input until either the same word occurs twice in succession or all
 * the words have been read. Use a while loop to read the text one word at a
 * time. Use the break statement to terminate the loop if a word occurs twice
 * in succession. Print the word if it occurs twice in succession, or else
 * print a message saying that no word was repeated.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

int main()
{
	std::string word, prevWord;
	bool match = false;

	while (std::cin >> word) {
		if (!prevWord.empty() && word == prevWord) {
			match = true;
			break;
		}
		prevWord = word;
	}

	if (match)
		std::cout << word << '\n';
	else
		std::cout << "no word was repeated\n";

	return 0;
}
