/*
 * Exercise 16.50: Define the functions from the previous exercise so that they
 * print an identifying message. Run the code from that exercise. If the calls
 * behave differently from what you expected, make sure you understand why.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

template <typename T> void f(T)
{
	std::cout << "f(T)\n";
}

template <typename T> void f(const T*)
{
	std::cout << "f(const T*)\n";
}

template <typename T> void g(T)
{
	std::cout << "g(T)\n";
}

template <typename T> void g(T*)
{
	std::cout << "g(T*)\n";
}

int main() {
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;
	g(42); g(p); g(ci); g(p2);
	f(42); f(p); f(ci); f(p2);
	return 0;
}
