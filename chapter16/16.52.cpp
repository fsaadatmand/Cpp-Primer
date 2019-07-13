/*
 * Exercise 16.52: Write a program to check your answer to the previous
 * question.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
	std::cout << "Args is " << sizeof... (Args) << "; "
			  << "rest is " << sizeof... (rest) << '\n';
}

int main() {
	int i = 0; double d = 3.14; std::string s = "how now brown cow";
	foo(i, s, 42, d); // Args is 3; rest is 3
	foo(s, 42, "hi"); // Args is 2; rest is 2
	foo(d, s);        // Args is 1; rest is 1
	foo("hi");        // Args is 0; rest is 0
	return 0;
}
