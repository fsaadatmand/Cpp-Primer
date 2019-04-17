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
	std::cout << "I'm empty!\n";
}

void f(int)
{
	std::cout << "I'm number 1!\n";
}

void f(int x, int y)
{
	std::cout << "I add two ints: " 
		      << x + y << '\n';
}

void f(double x, double y)
{
	std::cout << "I add two doubles: "
		      << x + y << '\n';
}

int main() {
	//f(2.56, 42);    // ambiguous
	f(42);
	f(42, 0);
	f(2.56, 3.14);
	return 0;
}
