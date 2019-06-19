/*
 * Exercise 16.6: How do you think the library begin and end functions that
 * take an array argument work? Define your own versions of these functions.
 * array.
 *
 * By Faisal Saadatmand
 */

/*
 * Answer: they are function templates that take a typename parameter for the
 * array type and the function's return type. They also use nontype parameters
 * for the size of the array. The implementation is quite simple: begin returns
 * a pointer to the first element, while end returns a pointer to one past the
 * last element of the array that was passed as an argument,
 */

#include <iostream>

template <typename T, unsigned N>
T* begin(T (&arr)[N])
{
	return arr;
}

template <typename T, unsigned N>
T* end(T (&arr)[N])
{
	return &arr[N];
}

int main()
{
	int a[5] = {1, 2, 3, 4 , 5};
	double d[] = {9.3, 2.4, 36.90, 4.22 , 22.7};

	auto a_first = begin(a);
	auto a_last = end(a);
	std::cout << *a_first << ' ';
	std::cout << *(a_last - 1) << '\n';

	auto d_first = begin(d);
	auto d_last = end(d);
	std::cout << *d_first << ' ';
	std::cout << *(d_last - 1) << '\n';
	return 0;
}
