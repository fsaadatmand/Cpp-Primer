/*
 * Exercise 9.31: The program on page 354 to remove even valued elements and
 * duplicate odd ones will not work on a list or forward_list. Why? Revise the
 * program so that it works on these types as well.
 *
 * By Faisal Saadatmand
 *
 * Answer: we cannot perform iterator arithmetic, such as iter += 2, with
 * either a list or a forward_list. For a forward_list, we must use the special
 * insert and erase operations for a forward_list, refer to table 9.8, p.351.
 * Moreover, we must ensure that the current and the previous iterators are
 * refreshed appropriately on each iteration.
 */

#include <iostream>
#include <forward_list>
#include <list>

int main()
{
	// list
	std::list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto iter = li.begin();
	while (iter != li.end())
		if (*iter % 2) {
			iter = li.insert(iter, *iter);
			++iter;
			++iter;
		} else
			iter = li.erase(iter);

	std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto prev = fli.before_begin();
	auto curr = fli.begin();
	while (curr != fli.end())
		if (*curr % 2) {
			curr = fli.insert_after(prev, *curr);
			prev = curr++;
		} else {
			curr = fli.erase_after(prev);
			prev = curr;
		}

	for (const auto &element : li)
		std::cout << element << " ";
	std::cout << '\n';

	for (const auto &element : fli)
		std::cout << element << " ";
	std::cout << '\n';

	return 1;
}
