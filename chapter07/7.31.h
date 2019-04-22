/*
 * Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
 * Y, and Y has
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Y;         // forward declaration

class X {
	Y *pointerToY = nullptr;
};

class Y {
	X *pointerToX = nullptr;
};
