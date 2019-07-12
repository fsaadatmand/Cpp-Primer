/*
 * Exercise 16.47: Write your own version of the flip function and test it by
 * calling functions that have lvalue and rvalue reference parameters.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int v1, int &v2)
{
	std::cout << v1 << " " << ++v2 << std::endl;
}

void g(int &&i, int& j)
{
	std::cout << i << " " << j << std::endl;
}

int main()
{
	int i = 0;
	flip(f, i, 42); // f has an lvalue reference parameter
	flip(g, i, 42); // g has an rvalue reference parameter
	return 0;
}
