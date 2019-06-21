/*
 * Exercise 16.23: Predict when the call operator will be executed in your main
 * query program. If your expectations and what happens differ, be sure you
 * understand why.
 *
 * By Faisal Saadatmand
 */

/*
 * Since we are passing DebugDelete() to a shared_ptr as a deleter, it will be
 * executed every time the shared_ptr's reference counter reaches 0
*/ 

#include <fstream>
#include <iostream>
#include "16.22.h" //  QueryResult

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <filename>\n";
		return -1;
	}
	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	runQueries(inFile);
	return 0;
}
