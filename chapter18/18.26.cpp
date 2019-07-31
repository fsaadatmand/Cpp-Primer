/*
 * Exercise 18.26: Given the hierarchy in the box on page 810, why is the
 * following call to print an error? Revise MI to allow this call to print to
 * compile and execute correctly.
 *
 * 	MI mi;
 * 	mi.print(42);
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

struct Base1 {
	void print(int) const
		{ std::cout << "Base1::print(int)\n"; }
	protected:
		int ival;
		double dval;
		char cval;
	private:
		int *id;
};

struct Base2 {
	void print(double) const
		{ std::cout << "Base2::print(double)\n"; }
	protected:
		double fval;
	private:
		double dval;
};

struct Derived : public Base1 {
	void print(std::string) const
		{std::cout << "Derived::print(std::string)\n"; }
	protected:
		std::string sval;
		double dval;
};

struct MI : public Derived, public Base2 {
	void print(std::vector<double>) const
		{ std::cout << "MI::print(vector<double>)\n"; }
	void print(int) const
		{ std::cout << "MI::print(int)\n"; }
	protected:
		int *ival;
		std::vector<double> dvec;
};

int main()
{
	MI mi;
	mi.print(42);
	return 0;
}
