/*
 * Exercise 7.43: Assume we have a class named NoDefault that has a constructor
 * that takes an int, but has no default constructor. Define a class C that has
 * a member of type NoDefault. Define the default constructor for C.
 *
 * by Faisal Saadatmand
 */

#include <iostream>

class NoDefault {
	public:
		NoDefault(int i) : x(i) {}
	private:
		int x;
};

class C {
	public:
		C(NoDefault value) : c_member(value) { }
		C() : C(0) {}  // default contructor delegate to NoDefault constructor
	private:
		NoDefault c_member;
};

int main()
{
	C obj(4);      // NoDefault constructor is called
	C obj2;        // default construct is called and delegates 
	               // initialization to NoDefault constructor
	return 0;
}
