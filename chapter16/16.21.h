/*
 * Exercise 16.21: Write your own version of DebugDelete.
 *
 * By Faisal Saadatmand
 */

#ifndef DEBUG_DELETER_H
#define DEBUG_DELETER_H

#include <iostream>
#include <memory>

class DebugDeleter {
	public:
		DebugDeleter(std::ostream &s = std::cerr) : os(s) {} 
		template <typename T> void operator()(T *p) const
		{ os << "deleting unique_ptr" << std::endl; delete p; }
	private:
		std::ostream &os;
};

#endif
