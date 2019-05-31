/*
 * Exercise 13.13: A good way to understand copy-control members and
 * constructors is to define a simple class with these members in which each
 * member prints its name:
 *
 * 	struct X {
 * 		X() {std::cout << "X()" << std::endl;}
 *		X(const X&) {std::cout << "X(const X&)" << std::endl;}
 * 	};
 *
 * Add the copy-assignment operator and destructor to X and write a program
 * using X objects in various ways: Pass them as nonreference and reference
 * parameters; dynamically allocate them; put them in containers; and so forth.
 * Study the output until you are certain you understand when and why each
 * copy-control member is used. As you read the output, remember that the
 * compiler can omit calls to the copy constructor.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <vector>

struct X {
	X() { std::cout << "X() " << &*this << std::endl; }
	X(const X&) { std::cout << "X(const X&) " << &*this << std::endl; }
	X& operator=(const X &);
	~X() {std::cout << "~X() " << &*this << std::endl; }
};

X&
X::operator=(const X &rhs)
{
	std::cout << "operator=(const X&) " << &*this << std::endl;
	return *this;
}

X func(const X a, const X &b)
{
	X c = a;
	return c;
}
int main()
{
	std::cout << "X a;\n";
	X a;
	std::cout << "\nX b;\n";
	X b;
	std::cout << "\na = b;\n";
	a = b;
	std::cout <<"\nX c(b);\n";
	X c(b);

	std::cout << "\nstd::vector<X> xvec{a, b, c};\n";
	std::vector<X> xvec1{a, b, c};

	std::cout << "\nxvec2 = vec1;\n";
	std::vector<X> xvec2(xvec1);

	std::cout << "\nxvec2.push_back(a);\n";
	xvec2.push_back(a);

	std::cout << "\nxvec2.pop_back();\n";
	xvec2.pop_back();

	std::cout << "\nfunc(a, b);\n";
	func(a, b);

	std::cout << "\nX *p = new X();\n";
	X *p = new X();

	std::cout << "\n*p = a;\n";
	*p = a;

	std::cout << "\nauto sp = std::make_shared<X>();\n";
	auto sp = std::make_shared<X>(a);
	
	std::cout << "\nsp = std::make_shared<X>(b);\n";
	sp = std::make_shared<X>(b);;

	std::cout << "\ndelete p;\n";
	delete p;

	std::cout << "\np = &c;\n";
	p = &c;

	std::cout << "\n*p = func(a, b);\n";
	*p = func(a, b);

	std::cout << "\ndestructor calls:\n";
	return 0;
}
