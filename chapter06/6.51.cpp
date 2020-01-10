/*
 * Exercise 6.51: Write all four versions of f. Each function should print a
 * distinguishing message. Check your answers for the previous exercise. If
 * your answers were incorrect, study this section until you understand why
 * your answers were wrong.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

void f()
{
	std::cout << "void f()\n";
}

void f(int)
{
	std::cout << "void f(int)\n";
}

void f(int, int)
{
	std::cout << "void f(int, int)\n";
}

void f(double, double)
{
	std::cout << "void f(double, double = 3.14)\n";
}

int main() {
//	f(2.56, 42); // ambiguous
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
