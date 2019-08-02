/*
 * Exercise 19.8: Write a typeid expression to see whether two Query_base
 * pointers point to the same type. Now check whether that type is an AndQuery.
 *
 * By Faisal Saadatmand
 */

#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include <string>
#include "Query.h"

int main()
{
	Query a("one"), b("two");
	Query_base *qb1 = new AndQuery(a, b); // up cast from AndQuery to Query_base
	Query_base *qb2 = new AndQuery(a, b); // up cast from AndQuery to Query_base

	if (typeid(*qb1) == typeid(*qb2)) {
		std::cout << "pointers are the same type: ";
		if (AndQuery *andQ = dynamic_cast<AndQuery *>(qb1)) // down cast
			std::cout << "AndQuery\n";
	}
	return 0;
}
