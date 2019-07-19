/*
 * Exercise 17.11: Define a data structure that contains an integral object to
 * track responses to a true/false quiz containing 10 questions. What changes,
 * if any, would you need to make in your data structure if the quiz had 100
 * questions?
 *
 * By Faisal Saadatmand
 */

#ifndef QUIZ_H
#define QUIZ_H

#include <bitset>

// for a quiz of 100 object it is better to use a bitset object instead.
//
// integral type holds a maximum of responses to 64 questions due hardware
// limitation of 64 bits per object
struct Quiz_integral {
	unsigned long long question;
};

// bitset object can hold more than the hardware limitation of 64 bits per
// object
struct Quiz {
	static constexpr size_t nQuestions = 100;
	std::bitset<nQuestions> questions;
};
#endif // QUIZ_H
