/*
 * Exercise 7.15: Add appropriate constructors to your Person class.
 *
 * By Faisal Saadatmand
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person;
std::istream& read(std::istream &, Person &);
std::ostream& print(std::ostream &, const Person &);

struct Person {
	// constructors
	Person() = default;
	Person(const std::string &n, const std::string &a)
		   : pName(n), pAddress(a) {} 
	Person(std::istream &is) { read(is, *this); }
	/// member functions
	std::string name() const { return pName; }
	std::string address() const { return pAddress; }
	//members
	std::string pName;
	std::string pAddress;
};

#endif
