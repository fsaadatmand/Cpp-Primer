/*
 * Exercise 19.6: Write an expression to dynamically cast a pointer to a
 * Query_base to a pointer to an AndQuery (§ 15.9.1, p. 636). Test the cast by
 * using objects of AndQuery and of another query type. Print a statement
 * indicating whether the cast works and be sure that the output matches your
 * expectations.
 *
 * By Faisal Saadatmand
 */

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include "Sales_data.h"

class Base {
	public:
	virtual ~Base() = default;
	virtual void name() const { std::cout << "Base\n"; }
};

class Derived : public Base {
	void name() const override { std::cout << "Derived\n"; }
};

// remember that type_info is implementation dependent
std::ostream& printType(std::ostream &os, const char *s)
{
	// exit condition
	if (!s)
		return os;
	// skip non-alphabetic characters
	while (!isalpha(*s))
		++s;
	// pointer
	if (*s == 'P') {
		os << "pointer to ";
		return printType(os, ++s);
	}
	// built-in types (not all types)
	if (*s == 'c')
		return os << "char";
	if (*s == 'd')
		return os << "double";
	if (*s == 'f')
		return os << "float";
	if (*s == 'i')
		return os << "int";
	if (*s == 'j')
		return os << "unsigned";
	// array
	if (*s == 'A') {
		os << "array of ";
		for (++s; isdigit(*s); ++s) {
			os << *s;
		}
		os << ' ';
		return printType(os, s);
	}
	// library string
	if (!strcmp(s, "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE"))
		return os << "string";
	return os << s;  // user defined types
}

int main()
{
	int arr[10];
	Derived d;
	Base *p = &d;
	int i = 42;
	printType(std::cout, typeid(i).name()) << '\n';
	printType(std::cout, typeid(&i).name()) << '\n';
	printType(std::cout, typeid(1.0).name()) << '\n';
	printType(std::cout, typeid('c').name()) << '\n';
	printType(std::cout, typeid(arr).name()) << '\n';
	printType(std::cout, typeid(p).name()) << '\n';
	printType(std::cout, typeid(*p).name()) << '\n';
	printType(std::cout, typeid(Sales_data).name()) << '\n';
	printType(std::cout, typeid(std::string).name()) << '\n';
	return 0;
}
