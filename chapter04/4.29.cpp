/*
 * Exercise 4.29: Predict the output of the following code and explain your
 * reasoning.  Now run the program. Is the output what you expected? If not,
 * figure out why.
 *
 * 		int x[10]; int *p = x;
 * 		cout << sizeof(x)/sizeof(*x) << endl;
 * 		cout << sizeof(p)/sizeof(*p) << endl;
 * 
 * By Faisal Saadatmand
 */

/*
 * answer:
 * 10
 * 2
 * see comments below.
*/

#include <iostream>

int main()
{
	using std::cout; using std::endl;

	int x[10]; int *p = x;
	// size of x / size of x[0] (int) is 40 / 4 = 10
	cout << sizeof(x)/sizeof(*x) << endl;
	//  size of pointer p / p[0] (or x[0]) is 8 / 4 = 2
	cout << sizeof(p)/sizeof(*p) << endl;

	return 0;
}
