/*
 * Exercise 7.5: Provide operations in your Person class to return the name and
 * address. Should these functions be const? Explain your choice.
 * 
 * By Faisal Saadatmand
 */

/*
 * Answer: yes, since these operations do not modify the members of the class
 * that they are returning.
 */
 
#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
	std::string get_name() const { return name; }
	std::string get_address() const { return address; }
	std::string name;
	std::string address;
};

#endif
