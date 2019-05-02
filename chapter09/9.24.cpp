/*
 * Exercise 9.24: Write a program that fetches the first element in a vector
 * using at, the subscript operator, front, and begin. Test your program on an
 * empty vector.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	if (!iv.empty()) {
		std::cout << "using:\n"
			     << "at\t\t" << iv.at(0) << '\n' 
				 << "subscript\t" << iv[0] << '\n'
				 << "front\t\t" << iv.front() << '\n'
				 << "begin\t\t" << *iv.begin() << '\n';
	}
	return 0;
}
