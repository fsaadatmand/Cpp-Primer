/*
 * Exercise 17.30: Revise your function again this time to take a minimum and
 * maximum value for the numbers that the function should return.
 *
 * By Faisal Saadatmand
 */

#include <ctime>
#include <iostream>
#include <random>

unsigned randUnsigned(const unsigned &min, const unsigned &max,
		const unsigned &seed = std::default_random_engine::default_seed)
{
	static std::default_random_engine e(seed);
	static std::uniform_int_distribution<unsigned> u(min, max);
	return u(e);
}

int main()
{
	for (size_t i = 0; i < 3; ++i) {
		for (std::size_t i = 0; i < 7; ++i)
			std::cout << randUnsigned(1, 50, time(NULL)) << ' ';
		std::cout << '\n';
	}
	return 0;
}
