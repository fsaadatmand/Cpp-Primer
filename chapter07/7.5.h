/*
 * Exercise 7.5: Provide operations in your Person class to return the name and
 * address. Should these functions be const? Explain your choice.
 * 
 * Answer: yes, since these operations do not modify the members of the class
 * they are returning.
 *
 * By Faisal Saadatmand
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
	std::string name() const { return pName; }
	std::string address() const { return pAddress; }
	std::string pName;
	std::string pAddress;
};

#endif
