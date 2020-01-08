/* 
 * Exercise 2.34: Write a program containing the variables and assignments from
 * the previous exercise. Print the variables before and after the assignments
 * to check whether your predictions in the previous exercise were correct. If
 * not, study the examples until you can convince yourself you know what led
 * you to the wrong conclusion.
 *
 * By Faisal Saadatmand
*/

#include <iostream>

int main()
{
	int i = 0, &r = i;
	auto a = r; // a is an int (r is an alias for i, which has type int)
	const int ci = i, &cr = ci;
	auto b = ci; // b is an int (top-level const in ci is dropped)
	auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
	auto d = &i; // d is an int* (& of an int object is int*)
	auto e = &ci; // e is const int* (& of a const object is low-level const)
	auto &g = ci; // g is a const int& that is bound to ci
	std::cout << "Values before assignments" << std::endl;
	std::cout << " a: " << a << " b: " << b << " c: " << c
		      << " d: " << d << " e: " << e << " g: " << g << '\n';
	a = 42;
	b = 42;
	c = 42;
//	d = 42; // compilation error, Uncomment to test
//	e = 42; // compilation error. Uncomment to test
//	g = 42; // compilation error uncomment to test
	std::cout << "Values after assignments" << '\n';
	std::cout << " a: " << a << " b: " << b << " c: " << c
		      << " d: " << d << " e: " << e << " g: " << g << '\n';
	return 0;
}
