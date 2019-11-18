/*
 * Exercise 6.23: Write your own versions of each of the print functions
 * presented in this section. Call each of these functions to print i and j
 * defined as follows:
 *
 * 		int i = 0, j[2] = {0, 1};
 *
 * By Faisal Saadatmand
 */

/*
 * The C-style type casting should be avoided when possible, for it may result
 * in undefined behaviour (including in these examples). Its use here is for
 * illustrative purposes: it is to force the invocation of a particular
 * overloaded print function.
 */

#include <iostream>

void print(const char *);
void print(const int *, const int *);
void print(const int [], size_t);
void print(const int (&)[2]);
void print(int (*)[2], size_t);

void print(const char *s)
{
	std::cout << "print(const char *)\n";
	if (s)
		while (*s)
			std::cout << *s++;
}

void print(const int *beg, const int *end)
{
	std::cout << "print(const int *, const int *)\n";
	while (beg != end)
		std::cout << *beg++ << '\n';
}

void print(const int a[], size_t size)
{
	std::cout << "print(const int [], size_t)\n";
	for (size_t i = 0; i != size; ++i)
		std::cout << a[i] << '\n';
}

void print(const int (&a)[2])
{
	std::cout << "print(const int (&)[2]\n";
	for (auto element : a)
		std::cout << element << '\n';
}

void print(int (*matrix)[2], size_t rowSize)
{
	std::cout << "print(int (*)[2], size_t)\n";
	for (size_t i = 0; i < rowSize; ++i)
		for (size_t j = 0; j < 2; ++j)
			std::cout << matrix[i][j] << '\n';
}

int main()
{
	int i = 0, j[2] = {0, 1};
	// void print(const char *);
	print((const char *) &i); // not recommended
	print((const char *) &j); // not recommended
	// void print(const int [], size_t);
	print(&i, 1);
	print(j, 2);
	// void print(const int *, const int *);
	print(&i, &i + 1);
	print(&j[0], &j[2]); // could use std::begin(j) and std::end(j) instead
	// void print(const int (&)[2]);
	print((const int (&)[2]) i); // not recommended
	print(j);
	// void print(int (*)[2], size_t);
	print(&j, 1);
	return 0;
}
