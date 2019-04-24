/*
 * Exercise 7.43: Assume we have a class named NoDefault that has a constructor
 * that takes an int, but has no default constructor. Define a class C that has
 * a member of type NoDefault. Define the default constructor for C.
 *
 * by Faisal Saadatmand
 */

#include <iostream>

class Nodefault {
	public:
		Nodefault(int i) : x(i) {}
	private:
		int x;
};

class C {
	public:
		C(Nodefault value) : c_member(value) { }
		C() : C(0) {}  // default contructor delegate to Nodefault constructor
	private:
		Nodefault c_member;
};

int main()
{
	C obj(4);      // Nodefault constructor is called
	C obj2;        // default construct is called and delegates 
	               // initialization to Nodefault constructor
	return 0;
}
