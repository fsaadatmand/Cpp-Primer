/*
 * Exercise 18.3: There are two ways to make the previous code work correctly
 * if an exception is thrown. Describe them and implement them.
 *
 * By Faisal Saadatmand
 */

/*
 * (1) Use a smart pointer instead of a built-in pointer and new expression
 * (2) Allocate the array on the stack instead of the heap.
 */

#include <iostream>
#include <exception>
#include <memory>
#include <vector>

void exercise_samrtPtr(int *b, int *e)
{
	std::vector<int> v(b, e);
	std::unique_ptr<int[]> up(new int[v.size()]);
	throw std::runtime_error("smartPtr error");;
}

void exercise_stack(int *b, int *e)
{
	std::vector<int> v(b, e);
	int a[v.size()];
	throw std::runtime_error("stack error");;
}

int main()
{
	int a[10] = {0 , 1, 2, 3, 4, 5, 6, 7, 8, 9};
	try {
	exercise_samrtPtr(a, &a[10]);
	exercise_stack(a, &a[10]);
	}
	catch (std::runtime_error &error) {
		std::cerr << "caught exception " << error.what() << std::endl;
	}
	return 0;
}
