/*
 * Exercise 14.37: Write a class that tests whether two values are equal. Use
 * that object and the library algorithms to write a program to replace all
 * instances of a given value in a sequence.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class EqualInts {
	public:
		bool operator()(int a, int b) { return a == b; }
};

int main()
{
	using std::placeholders::_1;
	std::vector<int> ivec {5, 4, 68, 4, 32, 14, 4, 71};
	auto isEqual = std::bind(EqualInts(), _1, 4); // 4 is the value to match
	std::replace_if(ivec.begin(), ivec.end(), isEqual, 99); // replace with 99
	for (const auto &elem : ivec)
		std::cout << elem << ' ';
	std::cout << '\n';
	return 0;
}
