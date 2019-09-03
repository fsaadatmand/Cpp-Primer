/*
 * Exercise 19.7: Write the same cast, but cast a Query_base object to a
 * reference to AndQuery. Repeat the test to ensure that your cast works
 * correctly.
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
	Query_base *qb = new AndQuery(a, b); // up cast from AndQuery to Query_base

	try {
		AndQuery &andQ = dynamic_cast<AndQuery &>(*qb); // down cast to AndQuery
		std::cout << "success\n";
	} catch (std::bad_cast) {
		std::cout << "dynamic_cast failed\n";
	}
	return 0;
}
