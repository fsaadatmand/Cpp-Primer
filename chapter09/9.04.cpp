/*
 * Exercise 9.4: Write a function that takes a pair of iterators to a
 * vector<int> and an int value. Look for that value in the range and return a
 * bool indicating whether it was found.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

bool checkIteratorRange(std::vector<int>::const_iterator,
		                std::vector<int>::const_iterator, const int);

bool checkIteratorRange(std::vector<int>::const_iterator begin,
		                std::vector<int>::const_iterator end, const int n)
{
	if (begin + n < begin || begin + n > end)
		return false;
	return true;
}

int main()
{
	std::vector<int> vec(20);
	// IN RANGE
	// first element
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), 0) << '\n';
	// element #10
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), 9) << '\n';
	// last elelment
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), 19) << '\n';
	// one past the last element of vec(20)
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), 20) << '\n';

	// OUT OF RANGE
	// preceding begin
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), -1) << '\n';
	// beyond one past the last element of vec(20)
	std::cout << checkIteratorRange(vec.cbegin(), vec.end(), 21) << '\n';
	return 0;
}
