/*
 * Exercise 9.26: Using the following definition of ia, copy ia into a vector
 * and into a list. Use the single-iterator form of erase to remove the
 * elements with odd values from your list and the even values from your
 * vector.
 *
 *		int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <list>
#include <vector>

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	std::vector<int> iv;
	std::list<int> il;

	// copy ia into iv and il
	constexpr auto size = sizeof(ia) / sizeof(ia[0]);
	for (decltype(sizeof(ia)) i = 0; i < size; ++i) {
		iv.push_back(ia[i]);
		il.push_back(ia[i]);
	}

	// erase even numbers from iv
	auto it = iv.begin();
	while (it != iv.end())
		if (!(*it % 2))
			it = iv.erase(it);
		else
			++it;

	// erase odd numbers from il
	auto itl = il.begin();
	while (itl != il.end())
		if (*itl % 2)
			itl = il.erase(itl);
		else
			++itl;

	// print iv
	for (const auto &element : iv)
		std::cout << element << " ";
	std::cout << '\n';

	// print il
	for (const auto &element : il)
		std::cout << element << " ";
	std::cout << '\n';

	return 0;
}
