/*
 * Exercise 16.20: Rewrite the function from the previous exercise to use
 * iterators returned from begin and end to control the loop.
 *
 * By Faisal Saadatmand
 */

#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H

#include <ostream>

template <typename T, typename C = char>
std::ostream& print(std::ostream& os, const T& container, C delem = C())
{
	for (typename T::iterator it = container.begin();
			it != container.end(); ++it)  // auto would work too
		os << *it << delem;
	return os;
}
#endif
