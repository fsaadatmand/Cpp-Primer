/*
 * Exercise 18.30: Define a default constructor, a copy constructor, and a
 * constructor that has an int parameter in Base. Define the same three
 * constructors in each derived class. Each constructor should use its argument
 * to initialize its Base part.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

class Class {
	public:
		Class() { std::cout << "Class()\n"; }
		Class(const Class &) { std::cout << "Class(const Class&)\n"; }
		Class(int) { std::cout << "Class(int)\n"; }
};

class Base : public Class {
	public:
		Base() { std::cout << "Base()\n"; }
		// implicitly copy-initialize Class members
		Base(const Base &rhs) : ival(rhs.ival)
			{ std::cout << "Base(const Base&)\n"; }
		Base(int i) : ival(i) { std::cout << "Base(int)\n"; }
	private:
		int ival = 0;
};

class D1 : virtual public Base {
	public:
		D1() { std::cout << "D1()\n"; }
		D1(const D1 &rhs) : Base(rhs) { std::cout << "D1(const D1&)\n"; }
		D1(int i) : Base(i) {}
};

class D2 : virtual public Base {
	public:
		D2() { std::cout << "D2()\n"; }
		D2(const D2 &rhs) : Base(rhs) { std::cout << "D2(const D2&)\n"; }
		D2(int i) : Base(i) {}
};

class MI : public D1, public D2 {
	public:
		MI() { std::cout << "MI()\n"; }
		MI(const MI &rhs) : Base(rhs), D1(rhs), D2(rhs)
			{ std::cout << "MI(const MI&)\n"; }
		MI(int i) : Base(i), D1(i), D2(i) {}
};

class Final : public MI, public Class {
	public:
		Final() { std::cout << "Final()\n"; }
		Final(const MI &rhs) : Base(rhs), MI(rhs), Class(rhs)
			{ std::cout << "Final(const Final&)\n"; }
		Final(int i) : Base(i), MI(i), Class(i) {}
};

int main()
{
	std::cout << ">>> constructor that takes int <<<\n";
	Final obj1(42);
	std::cout << ">>> copy-constructor <<<\n";
	Final obj2(obj1); 
	return 0;
}
