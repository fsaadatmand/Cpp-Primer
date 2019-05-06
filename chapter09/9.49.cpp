/*
 * Exercise 9.49: A letter has an ascender if, as with d or f, part of the
 * letter extends above the middle of the line. A letter has a descender if, as
 * with p or g, part of the letter extends below the line. Write a program that
 * reads a file containing words and reports the longest word that contains
 * neither ascenders nor descenders.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " file\n";
		return -1;
	}

	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "Could not open " + std::string(*argv) << '\n';
		return -1;
	}

	std::string alphabets("abcdefghijklmnopqrstuvwxyz \
			ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::string ascenderAndDescender("bdfghijklpqty");
	std::string word, longestWord;
	while (inFile >> word) {
		if (alphabets.find_first_of(word) != std::string::npos
				&& word.find_first_of(ascenderAndDescender) == std::string::npos)
			if (word.size() > longestWord.size())
				longestWord = word;
	}
	inFile.close();
	(!longestWord.empty()) ? std::cout << longestWord << '\n'
		                   : std::cout << "No word was found\n";
	return 0;
}
