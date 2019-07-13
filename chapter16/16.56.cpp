/*
 * Exercise 16.56: Write and test a variadic version of errorMsg.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>

// print any type we don't otherwise handle
template <typename T>
std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

// print pointer as their pointer value, followed by the object to which the
// pointer points. NB: this function will not work with char *
template <typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p); // calls debug_rep(const T&) to print
	else
		ret << "null pointer";
	return ret.str();
}

// nontemplate function: prints string inside double quotes
std::string debug_rep(const std::string &s)
{
	return '"' + s + '"';
}

// declaration is not necessary here but is a good practice.
std::string debug_rep(const std::string &s); 

// convert the character pointers to string call the string version of debug_rep
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}

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

// call debug_rep on each argument in the call to print
template <typename... Args>
std::ostream& errorMeg(std::ostream &os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}

int main() {
	int i = 32;
	errorMeg(std::cerr, 42, "some string", 5.6, &i) << '\n';
	return 0;
}
