/*
 * Exercise 16.39: Use an explicit template argument to make it sensible to
 * pass two string literals to the original version of compare from § 16.1.1
 * (p. 652).
 *
 * By Faisal Saadatmand
 */

#include <iostream>

template <typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main() {
	std::cout << compare<const char *>("world", "world") << '\n';
	return 0;
}
