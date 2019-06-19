/*
 * Exercise 16.2: Write and test your own versions of the compare functions.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <functional>

template <typename T>
int compare (const T &v1, const T &v2)
{
	if (std::less<T>()(v1, v2)) return -1;
	if (std::less<T>()(v2, v1)) return 1;
	return 0;
}

int main()
{
	int x = 10, y = 20, z = 10;
	std::cout << compare(x, y) << '\n';
	std::cout << compare(y, x) << '\n';
	std::cout << compare(x, z) << '\n';
	return 0;
}
