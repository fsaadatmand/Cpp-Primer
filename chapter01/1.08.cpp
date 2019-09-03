// Exercise 1.8: Indicate which, if any, of the following output statements are
// legal: 
//
// 	std::cout << "/*";
// 	std::cout << "*/";
// 	std::cout << /* "*/" */;
// 	std::cout << /* "*/" /* "/*" */;
//
// After you’ve predicted what will happen, test your answers by compiling a
// program with each of these statements. Correct any errors you encounter.
//
// By Faisal Saadatmand

#include <iostream>

int main()
{
	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "*/" */;          // illegal
	std::cout << /* "*/" /* "/*" */;
	return 0;
}
