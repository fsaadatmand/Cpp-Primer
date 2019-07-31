/*
 * Exercise 19.1: Write your own operator new(size_t) function using malloc and
 * use free to write the operator delete(void*) function.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <cstdlib>
#include <stdexcept>

void *operator new(std::size_t size)
{
	void *mem = nullptr;
	if (!(mem = malloc(size)))
		throw std::bad_alloc();
	std::cout << "operator new(std::size_t)\n";
	return mem;
}

void operator delete(void *mem) noexcept
{
	free(mem);
	std::cout << "operator delete(void *)\n";
}

int main()
{
	auto *p = new int(42);
	std::cout << *p << '\n';
	delete p;
	return 0;
}
