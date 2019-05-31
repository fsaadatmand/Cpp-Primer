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

X func1(const X a)
{
	X w = a;
	return w;
}

X &func2(X &a)
{
	return a;
}

X *func3(X *a)
{
	return a;
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

	// vector is reallocated
	std::cout << "\nxvec2.push_back(a);\n";
	xvec2.push_back(a);

	std::cout << "\nxvec2.pop_back();\n";
	xvec2.pop_back();

	std::cout << "\nfunc(a);\n";
	func1(a);

	std::cout << "\nfunc2(a);\n";
	func2(a);

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

	// *p = a;
	std::cout << "\n*p = func1(a);\n";
	*p = func1(a);

	std::cout << "\n*p = func3(p);\n";
	p = func3(p);

	std::cout << "\nX *arr = new X[3] ();\n";
	X *arr1 = new X[3] ();

	std::cout << "\narr1[0] = c;\n";
	arr1[0] = a;
	std::cout << "arr1[1] = c;\n";
	arr1[1] = b,
	std::cout << "arr1[2] = c;\n";
	arr1[2] = c;

	std::cout << "\nX *arr2 = new X[3] {a, b, c};\n";
	X *arr2 = new X[3] {a, b, c};

	std::cout << "\nX x = arr1[0];\n";
	X x = arr1[0];
	std::cout << "\nX y = arr2[0];\n";
	X y = arr2[0];

	std::cout << "\ndelete [] arr1;\n";
	delete [] arr1;
	std::cout << "\ndelete [] arr2;\n";
	delete [] arr2;

	std::cout << "\ndestructor calls: inverse order:\n";
	return 0;
}
