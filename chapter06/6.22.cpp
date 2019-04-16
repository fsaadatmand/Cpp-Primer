/*
 * Exercise 6.22: Write a function to swap two int pointers.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

void swap(int **, int **);

void swap(int **pa, int **pb)
{
	int *temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main()
{
	int x = 3, y = 5;
	int *px = &x, *py = &y;

	std::cout << "BEFORE calling swap():\t"
		       << "x = " << px << " " << *px << '\t'
		       << "y = " << py << " " << *py << '\n';
	swap(&px, &py);
	std::cout << "AFTER calling swap():\t"
		       << "x = " << px << " " << *px << '\t'
		       << "y = " << py << " " << *py << '\n';

	return 0;
}
