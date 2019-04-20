/*
 * Exercise 7.22: Update your Person class to hide its implementation. 
 *
 * By Faisal Saadatmand
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
	// friends for non-members
	friend std::istream& read(std::istream &, Person &);
	friend std::ostream& print(std::ostream &, const Person &);
	public:
	// constructors
	Person() = default;
	Person(const std::string &n, const std::string &a)
		   : pName(n), pAddress(a) {} 
	Person(std::istream &is) { read(is, *this); }
	/// member functions
	std::string name() const { return pName; }
	std::string address() const { return pAddress; }
	private:
	//members
	std::string pName;
	std::string pAddress;
};

// non-memebrs
std::istream& read(std::istream &, Person &);
std::ostream& print(std::ostream &, const Person &);

#endif
