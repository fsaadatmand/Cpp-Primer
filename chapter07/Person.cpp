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
