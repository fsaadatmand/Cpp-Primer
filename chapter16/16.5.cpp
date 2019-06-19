/*
 * Exercise 16.5: Write a template version of the print function from § 6.2.4
 * (p. 217) that takes a reference to an array and can handle arrays of any
 * size and any element type.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
	for (auto const elem : arr)
		std::cout << elem << '\n';
}

int main()
{
	print("hello, mom!");
	int ia[] = {1, 2, 3, 4, 5};
	print(ia);

	return 0;
}
