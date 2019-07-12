/*
 * Exercise 16.48: Write your own versions of the debug_rep functions.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>

// print any type we don't otherwise hnadle
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

// declarations are not necessary here but are a good practice.
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

int main() {
	std::string s("hi");
	std::cout << debug_rep(s) << '\n'; // nontemplate version is preferred
	std::cout << debug_rep(&s) << '\n'; // pointer version is instantiated
	std::cout << debug_rep("hi") << '\n'; // calls debug(const char *p)
	char arr[] = "hi", *p = arr; // p is a char * (nonconst)
	std::cout << debug_rep(p) << '\n'; // calls debug_rep(char *p)
	return 0;
}
