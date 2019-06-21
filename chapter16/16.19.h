
/*
 * Exercise 16.19: Write a function that takes a reference to a container and
 * prints the elements in that container. Use the container’s size_type and
 * size members to control the loop that prints the elements.
 *
 * By Faisal Saadatmand
 */

#ifndef PRINT_CONTAINER_H
#define PRINT_CONTAINER_H

#include <ostream>

template <typename T, typename C = char>
std::ostream& print(std::ostream& os, const T& container, C delem = '\0')
{
	for (typename T::size_type i = 0; i < container.size(); ++i)
		os << container[i] << delem;
	return os;
}
#endif
