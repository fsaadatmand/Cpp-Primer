/*
 * Exercise 6.22: Write a function to swap two int pointers.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void swap(int **p, int **q)
{
	auto temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	int x = 3, y = 5;
	int *px = &x, *py = &y;
	std::cout << "BEFORE calling swap():\n"
		       << " px = " << px << " *px = " << *px << '\t' <<'\n'
		       << " py = " << py << " *py = " << *py << '\n';
	swap(&px, &py);
	std::cout << "\nAFTER calling swap():\n"
		       << " px = " << px << " *px = " << *px << '\t' <<'\n'
		       << " py = " << py << " *py = " << *py << '\n';
	return 0;
}
