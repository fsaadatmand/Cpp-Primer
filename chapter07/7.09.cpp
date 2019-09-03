/*
 * Exercise 7.9: Add operations to read and print Person objects to the code
 * you wrote for the exercises in § 7.1.2 (p. 260).
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include "Person.h"

std::istream& read(std::istream &is, Person &person)
{
	is >> person.pName >> person.pAddress;
	return is;
}

std::ostream& print(std::ostream &os, const Person &person)
{
	os << person.name() << " " << person.address();
	return os;
}
