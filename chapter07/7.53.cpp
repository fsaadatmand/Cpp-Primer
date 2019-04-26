/*
 * Exercise 7.53: Define your own version of Debug.
 *
 * Note: As of C++14, a constexpr member is not implicitly a const. That's why
 * any() had to be explicitly marked as a const member function, otherwise the
 * code would not compile. 
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Debug {
	public:
		constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
		constexpr Debug(bool h, bool i, bool o) :
			                             hw(h), io(i), other(o) {}
		constexpr bool any() const { return hw || io || other; }
		void set_io(bool b) { io = b; }
		void set_hw(bool b) { hw = b; }
		void set_other(bool b) { hw = b; }

	private:
		bool hw;    // hardware errors other than IO errors
		bool io;    // IO errors
		bool other; // other errors
};

int main()
{
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
		std::cerr << "print appropriate messages\n";
	constexpr Debug prod(false);
	if (prod.any())
		std::cerr << "print an error message\n";

	return 0;
}
