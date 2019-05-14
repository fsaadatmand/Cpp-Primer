/*
 * Exercise 11.13: There are at least three ways to create the pairs in the
 * program for the previous exercise. Write three versions of that program,
 * creating the pairs in each way. Explain which form you think is easiest to
 * write and understand, and why.
 *
 * By Faisal Saadatmand
 *
 * Answer: the list initialization is the easiest, because the syntax suggests
 * that we are 'attaching' two object together to form one. Though the
 * make_pair syntax is the more explicit one, which could make it easier to
 * read in certain cases, it could become tedious very quickly to have to write
 * a function call every time we need to form a pairs. For example, this is
 * especially true if the pairs we were trying to initialize were part of
 * another list initialized container.
 *
 */

#include <iterator>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{

	std::vector<std::pair<std::string, int>> pair_vec1;
	std::vector<std::pair<std::string, int>> pair_vec2;
	std::vector<std::pair<std::string, int>> pair_vec3;
	std::pair<std::string, int> p;
	std::string word;
	int number;

	while (std::cin >> word && std::cin >> number) {
		pair_vec1.push_back({word, number});                      // method #1
		pair_vec2.push_back(make_pair(word, number));             // method #2
		pair_vec3.push_back({p.first = word, p.second = number}); // method #3
	}

	for (const auto &pair : pair_vec1)
		std::cout << pair.first << ' '
			      << pair.second << '\n';
	for (const auto &pair : pair_vec2)
		std::cout << pair.first << ' '
			      << pair.second << '\n';
	for (const auto &pair : pair_vec3)
		std::cout << pair.first << ' '
			      << pair.second << '\n';
	return 0;
}
