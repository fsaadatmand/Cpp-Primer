/*
 * Exercise 19.6: Write an expression to dynamically cast a pointer to a
 * Query_base to a pointer to an AndQuery (§ 15.9.1, p. 636). Test the cast by
 * using objects of AndQuery and of another query type. Print a statement
 * indicating whether the cast works and be sure that the output matches your
 * expectations.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <typeinfo>
#include <string>
#include "Query.h"

int main()
{
	Query a("one"), b("two");
	Query_base *qbAnd = new AndQuery(a, b); // up cast from AndQuery to Query_base
	Query_base *qbOr = new OrQuery(a, b);  // up cast from OrQuery to Query_base

	if (AndQuery *andQ = dynamic_cast<AndQuery *>(qbAnd)) { // down cast to AndQuery
		if (typeid(*andQ) == typeid(*qbOr)) 
			std::cout << "are equal\n";
		else
			std::cout << "not equal\n";
	} else
		std::cout << "dynamic_cast failed\n";
	return 0;
}
