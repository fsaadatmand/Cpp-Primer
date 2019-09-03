/*
 * Exercise 19.4: Using the classes defined in the first exercise, rewrite the
 * following code to convert the expression *pa to the type C&:
 *
 *	if (C *pc = dynamic_cast< C* >(pa)) {
 *		// use C’s members
 *	} else {
 *		// use A’s members
 *	}
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <stdexcept>

class A {
	public:
		A() = default;
		virtual ~A() noexcept = default;
};

class B : virtual public A {
	public:
		B() = default;
};

class C : public B {
	public:
		C() = default;
		int ival = 42;
};

class D : public B, virtual public A  {
	public:
		D() = default;
};


int main()
{
	A *pa = new C;
	if (C *pc = dynamic_cast<C *>(pa)) {
		std::cout << "succeed: C *pc = dynamic_cat<C *>(pa)\n";
		try {
			const C &rc = dynamic_cast<const C &>(*pa);
			std::cout << "succeed: const C &rc = dynamic_cast<const C &>(*pa)\n"
				<< "c.ival: " << rc.ival << '\n';
		} catch (std::bad_cast) {
			std::cout << "fail: const C &rc = dynamic_cast<const C &>(*pa)\n";
		}
	} else {
		std::cout << "fail: C *pc = dynamic_cat<C *>(pa)\n";
		// use A’s members
	}
	return 0;
}
