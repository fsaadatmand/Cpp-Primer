/*
 * Exercise 2.35: Determine the types deduced in each of the following
 * definitions. Once you’ve figured out the types, write a program to see
 * whether you were correct.
 *
 *		const int i = 42;
 *		auto j = i; const auto &k = i; auto *p = &i;
 *		const auto j2 = i, &k2 = i;
 *
 * By Faisal Saadatmand
 */

/*
 * Answer:
 * auto j = i; const auto &k = i; auto *p = &i;
 * 		j is an int; top-level const is dropped.
 * 		k is a const reference to a const int bound to i.
 * 		p is a pointer to a const int;
 *
 * const auto j2 = i, &k2 = i;
 * 	j2 is a const int; top-level const deduced
 * 	k2 is a const reference to const int, bound to i
 */

#include <iostream>

int main()
{
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;
	// typeid() code is borrowed from https://github.com/Mooophy
    // print i means int, and PKi means pointer to const int.
    std::cout   << "j is "      << typeid(j).name()
                << "\nk is "    << typeid(k).name()
                << "\np is "    << typeid(p).name()
                << "\nj2 is "   << typeid(j2).name()
                << "\nk2 is "   << typeid(k2).name()
                << std::endl;
	std::cout << std::endl;
	std::cout << "Values before assignment" << std::endl;
	std::cout << "j:" << j << " k:" << k << " *p:" << *p << std::endl;
	j = 60;
//	k = 60; // compilation error: because k is reference to a const int
//	*p = 60;// compilation error: because p is a pointer to a constant int; top level const is ignored
	std::cout << "Values before assignment" << std::endl;
	std::cout << "j:" << j << " k:" << k << " *p:" << *p << std::endl;
//	j2 = 60;                // compilation error: j2 is const int
//	k2 = 60;                // compilation error: j2 is const int
	return 0;
}
