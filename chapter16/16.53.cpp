/*
 * Exercise 16.53: Write your own version of the print functions and test them
 * by printing one, two, and five arguments, each of which should have
 * different types.  
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

// nonvariadic function to end the recursion and print the last element
template <typename T>
std::ostream& print(std::ostream &os, const T &t)
{
	return os << t;
}

// recursive variadic function template
template <typename T, typename... Args>
std::ostream& print(std::ostream&os, const T &t, const Args&... rest)
{
	os << t << ' ';
	return print(os, rest...);
}

int main() {
	int i = 0; double d = 3.14; std::string s = "how h brown cow";
	print(std::cout, "one argument") << '\n';
	print(std::cout, "two arguments", 2) << '\n';
	print(std::cout, "five arguments", i, s, d, 42) << '\n';
	return 0;
}
