/*
 * Exercise 6.23: Write your own versions of each of the print functions
 * presented in this section. Call each of these functions to print i and j
 * defined as follows:
 * 		int i = 0, j[2] = {0, 1};
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

void print(const char *);        // cannot use to print i or j
void print(const int *, const int *);
void print(const int [], size_t);
void print(const int (&)[2]);    // cannot use to print i

void print(const int *s)
{
	if (!s)
		return;
	while (*s)
		std::cout << *s++;
}

void print(const int *start, const int *end)
{
	while (start != end)
		std::cout << *start++ << '\n';
}

void print(const int a[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
		std::cout << a[i] << '\n';
}

void print(const int (&a)[2])
{
	for (auto element : a)
		std::cout << element << '\n';
}

int main()
{
	int i = 0, j[2] = {0, 1};
	int *pi = &i;
	int (&rj)[2] = j;

	print(pi, pi + 1);
	print(&j[0], &j[2]);

	print(&i, 1);
	print(j, 2);

	print(rj);

	return 0;
}
