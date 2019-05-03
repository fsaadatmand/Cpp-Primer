/*
 * Exercise 9.34: Assuming vi is a container of ints that includes even and odd
 * values, predict the behavior of the following loop. After you’ve analyzed
 * this loop, write a program to test whether your expectations were correct.
 *
 * 		iter = vi.begin();
 * 		while (iter != vi.end())
 * 			if (*iter % 2)
 * 				iter = vi.insert(iter, *iter);
 * 			++iter;
 *
 * By Faisal Saadatmand
 *
 *	Answer; this program has a two errors: iter is missing a type in its
 *	definition, and, more important, the iter incrementation is outside of the
 *	while loop. As it stands, the program will find the first odd value in the
 *	container and will insert a duplicate BEFORE it. It will repeat the process
 *	infinitely starting from the newly inserted element each iteration.
 *
 *	That said, even if we corrected the aforementioned errors, the program will
 *	behave in a similar manner, with the exception that the insertion will
 *	happen at the position before the original odd value at each iteration.
 */

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2)
			iter = vi.insert(iter, *iter);
		++iter;        // wrongly incremented
	}
	
	for (const auto &elem : vi)
		std::cout << elem << " ";
	std::cout << '\n';
	return 0;
}
