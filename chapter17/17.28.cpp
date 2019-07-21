/*
 * Exercise 17.28: Write a function that generates and returns a uniformly
 * distributed random unsigned int each time it is called.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <random>

unsigned randUnsigned()
{
	static std::default_random_engine e;
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

int main()
{
	for (std::size_t i = 0; i < 7; ++i)
		std::cout << randUnsigned() << ' ';
	std::cout << '\n';

	for (std::size_t i = 0; i < 7; ++i)
		std::cout << randUnsigned() << ' ';
	std::cout << '\n';
	return 0;
}
