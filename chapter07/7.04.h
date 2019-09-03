/*
 * Exercise 7.4: Write a class named Person that represents the name and
 * address of a person. Use a string to hold each of these elements. Subsequent
 * exercises will incrementally add features to this class.
 *
 * By Faisal Saadatmand
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
	std::string name;
	std::string address;
};

#endif
