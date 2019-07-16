/*
 * Exercise 16.65: In § 16.3 (p. 698) we defined overloaded two versions of
 * debug_rep one had a const char* and the other a char* parameter. Rewrite
 * these functions as specializations.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <string>

// base template (a)
// print any type we don't otherwise handle
template <typename T>
std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

// base template (b)
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

// IMPORTANT: specialization of (b) - char *p version
template <>
std::string debug_rep(char *p)
{
	std::cout << "debug_rep(char *p)\n";
	return debug_rep(std::string(p));
}

// IMPORTANT: specialization of (b) - const char *p version
template <>
std::string debug_rep(const char *p)
{

	std::cout << "debug_rep(const char *p)\n";
	return debug_rep(std::string(p));
}

int main() {
	std::string s("hi");
	// nontemplate version is preferred
	std::cout << debug_rep(s) << '\n';
	// pointer version is instantiated
	std::cout << debug_rep(&s) << '\n';
	// calls specialized template of (b); debug(const char *p)
	std::cout << debug_rep("hi") << '\n';
	char arr[] = "hi", *p = arr; // p is a (nonconst) char *
	// calls specialized template of (b); debug_rep(char *p)
	std::cout << debug_rep(p) << '\n';
	return 0;
}
