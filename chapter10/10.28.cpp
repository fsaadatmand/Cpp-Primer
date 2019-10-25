/*
 * Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
 * into three other containers. Use an inserter, a back_inserter, and a
 * front_inserter, respectively to add elements to these containers. Predict
 * how the output sequence varies by the kind of inserter and verify your
 * prediction by running the programs.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <iterator>
#include <deque>
#include <list>
#include <numeric> // iota
#include <string>
#include <vector>

int main()
{
	// use iota (p. 882) to populate the source vector with values 1-9.
	std::vector<int> source(9);
	std::iota(source.begin(), source.end(), 1);
	// back_inserter: output 1 2 3 4 5 6 7 8 9
	std::vector<int> ivec;
	copy(source.cbegin(), source.cend(), back_inserter(ivec)); 
	// front inserter: output 9 8 7 6 5 4 3 2 1
	std::deque<int> ideq;
	copy(source.cbegin(), source.cend(), front_inserter(ideq));
	// inserter: output 1 2 3 4 5 6 7 8 9
	std::list<int> ilist;
	copy(source.cbegin(), source.cend(), inserter(ilist, ilist.begin()));

	// print the containers
	std::cout << "back_inserter and vector:" ;
	for (const auto &elem : ivec)
		std::cout << ' ' << elem;
	std::cout << '\n';

	std::cout << "front_inserter and deque:"; 
	for (const auto &elem : ideq)
		std::cout << ' ' <<  elem;
	std::cout << '\n';

	std::cout << "inserter and list:" ;
	for (const auto &elem : ilist)
		std::cout <<  ' ' << elem;
	std::cout << '\n';
	
	return 0;
}
