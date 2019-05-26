/*
 * Exercise 12.26: Rewrite the program on page 481 using an allocator.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <string>

int main()
{
	std::allocator<std::string> alloc;
	std::string s;
	const size_t n = 10;
	const auto p = alloc.allocate(n); 
	auto q = p;
	while (std::cin >> s && q != p + n)
		alloc.construct(q++, s);
	size_t i = 0;
	while (q != p) {
		std::cout << p[i++] << std::endl;
		alloc.destroy(--q);
	}
	alloc.deallocate(q, i);  // deallocates p as well
	q = nullptr;
	return 0;
}
