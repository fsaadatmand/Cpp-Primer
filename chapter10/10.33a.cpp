/*
 * Exercise 10.33: Write a program that takes the names of an input file and
 * two output files. The input file should hold integers. Using an
 * istream_iterator read the input file. Using ostream_iterators, write the odd
 * numbers into the first output file. Each value should be followed by a
 * space. Write the even numbers into the second file. Each of these values
 * should be placed on a separate line.
 *
 * By Faisal Saadatmand
 *
 * Note: this version uses library algoithms and a vector to store and process
 * the numbers.
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Usage: " << *argv << " inFile oddFile evenFile\n";
		return -1;
	}
	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "Could not open " << *argv << '\n';
		return -1;
	}
	std::istream_iterator<int> in_iter(inFile), eof;
	std::ofstream oddFile(*++argv), evenFile(*++argv);
	std::ostream_iterator<int> out_iter_odd(oddFile,  " "),
		                       out_iter_even(evenFile, "\n");
	std::vector<int> ivec(in_iter, eof);
	if (in_iter == eof) {
		std::cerr << "Invalid input ";
		return -1;
	}
	copy_if(ivec.cbegin(), ivec.cend(), out_iter_odd,
			[](const int &number) { return number % 2; });
	copy_if(ivec.cbegin(), ivec.cend(), out_iter_even,
			[](const int &number) { return !(number % 2); });
	return 0;
}
