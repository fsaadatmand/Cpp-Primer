/*
 * Exercise 15.20: Write code to test your answers to the previous two
 * exercises.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

class Base {
	public:
		void pub_mem();
		void memfcn(Base &b) { b = *this; }
	protected:
		int prot_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv : private Base {
	void memfcn(Base &b) { b = *this; }
	int f() { return prot_mem; }
	protected:
		int i;
};

struct Prot_Derv : protected Base {
	void memfcn(Base &b) { b = *this; }
	int f() { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
	void memfcn(Base &b) { b = *this; }
	int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
	void memfcn(Base &b) { b = *this; } // error
	int use_base() { return prot_mem; } // error
};

struct Derived_from_Protected : public Prot_Derv {
	void memfcn(Base &b) { b = *this; }
	int use_base() { return prot_mem; }
};

int main()
{

	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Private dd2;
	Derived_from_Protected add3;

	Base *p = &d1; // d1 has type Pub_Derv
	p = &d2; // d2 has type Priv_Derv
	p = &d3; // d3 has type Prot_Derv
	p = &dd1; // dd1 has type Derived_from_Public
	p = &dd2; // dd2 has type Derived_from_Private
	p = &dd3; // dd3 has type Derived_from_Protected
	return 0;
}
