/*
 * Exercise 18.3: There are two ways to make the previous code work correctly
 * if an exception is thrown. Describe them and implement them.
 *
 * By Faisal Saadatmand
 */

/*
 * (1) Handle the exception locally in order to free p.
 * (2) Use a smart pointer instead.
 */

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

// 1. Handle exception
void exercise_1(int *b, int *e) {
	int *p;
	try {
		std::vector<int> v(b, e);
		p = new int[v.size()];
		std::ifstream in("ints");
		throw std::ios_base::failure("ifstream"); // simulate ifstream error
	} catch (std::exception &r) {
		delete[] p; // free  allocate memory before rethrowing
		throw;
	}
}

// 2. Use a unique pointer
void exercise_2(int *b, int *e) {
	std::vector<int> v(b, e);
	std::unique_ptr<int[]> p(new int[v.size()]);
	std::ifstream in("ints");
	throw std::ios_base::failure("ifstream"); // simulate ifstream error
}

int main()
{
	int a[10] = {0 , 1, 2, 3, 4, 5, 6, 7, 8, 9};
	try {
		exercise_1(a, &a[10]);
	}
	catch (std::exception &error) {
		std::cerr << "exercise_1: " << error.what() << std::endl;
	}
	try {
		exercise_2(a, &a[10]);
	}
	catch (std::exception &error) {
		std::cerr << "exercise_2: " << error.what() << std::endl;
	}
	return 0;
}
