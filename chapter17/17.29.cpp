/*
 * Exercise 17.29: Allow the user to supply a seed as an optional argument to
 * the function you wrote in the previous exercise.
 *
 * By Faisal Saadatmand
 */

#include <ctime>
#include <iostream>
#include <random>

unsigned randUnsigned(const unsigned &seed =
		std::default_random_engine::default_seed)
{
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<unsigned> u;
	return u(e);
}

int main()
{
	// default seed
	for (std::size_t i = 0; i < 7; ++i)
		std::cout << randUnsigned() << ' ';
	std::cout << '\n';
	for (std::size_t i = 0; i < 7; ++i)
		std::cout << randUnsigned() << ' ';
	std::cout << '\n';
	// user provided seed
	for (std::size_t i = 0; i < 7; ++i)
		std::cout << randUnsigned(time(NULL)) << ' ';
	std::cout << '\n';
	return 0;
}
