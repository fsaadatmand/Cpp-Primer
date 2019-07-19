/*
 * Exercise 17.10: Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a
 * bitset that has a 1 bit in each position corresponding to a number in this
 * sequence. Default initialize another bitset and write a small program to
 * turn on each of the appropriate bits.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <bitset>

int main()
{
	constexpr size_t size = 32;
	std::bitset<size> bitvec1(0x20212e);
	std::cout << "bitvev1: " << bitvec1 << '\n';

	std::bitset<size> bitvec2;
	for (size_t i = 0; i < bitvec1.size(); ++i)
		if (bitvec1.test(i))
			bitvec2.set(i, true);
	std::cout << "bitvec2: " << bitvec2 << '\n';
	return 0;
}
