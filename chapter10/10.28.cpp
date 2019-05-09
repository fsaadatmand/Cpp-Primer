/*
 * Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
 * into three other containers. Use an inserter, a back_inserter, and a
 * front_inserter, respectivly to add elements to these containers. Predict how
 * the output sequence varies
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <iterator>
#include <deque>
#include <list>
#include <string>
#include <vector>

int main()
{
	std::vector<int> source{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> ivec;
	std::deque<int> ideq;
	std::list<int> ilist;

	// back_inserter: output 1 2 3 4 5 6 7 8 9
	copy(source.cbegin(), source.cend(), back_inserter(ivec)); 
	// front inserter: output 9 8 7 6 5 4 3 2 1
	copy(source.cbegin(), source.cend(), front_inserter(ideq));
	// inserter: output 1 2 3 4 5 6 7 8 9
	copy(source.cbegin(), source.cend(), inserter(ilist, ilist.begin()));

	std::cout << "back_inserter and vector: " ;
	for (const auto &elem : ivec)
		std::cout << elem << ' ';
	std::cout << '\n';

	std::cout << "front_inserter and deque: "; 
	for (const auto &elem : ideq)
		std::cout << elem << ' ';
	std::cout << '\n';

	std::cout << "inserter and list: " ;
	for (const auto &elem : ilist)
		std::cout << elem << ' ';
	std::cout << '\n';
	
	return 0;
}
