/*
 * Exercise 14.38: Write a class that tests whether the length of a given
 * string matches a given bound. Use that object to write a program to report
 * how many words in an input file are of sizes 1 through 10 inclusive.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StringLength {
	public:
		StringLength(std::size_t l, std::size_t u) : lower(l), upper(u) {}
		bool operator()(const std::string &s) const
			{ return s.length() >= lower && s.length() <= upper; }
	private:
		std::size_t lower;
		std::size_t upper;
};

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " inputFile\n";
		return -1;
	}
	std::ifstream infile(*++argv);
	if (!infile) {
		std::cerr << "Could't open " << *argv << '\n';
		return -1;
	}
	std::vector<std::string> words;
	std::string word;
	std::size_t lower = 1, upper = 10;
	while (infile >> word)
		words.push_back(word);
	auto wc = std::count_if(words.cbegin(), words.cend(),
				StringLength(lower, upper));
	std::cout << wc << ((wc > 1) ? " words are " : " word is ")
		      << "within the bound " << lower << " and " << upper << '\n';
	return 0;
}
