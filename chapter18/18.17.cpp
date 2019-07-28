/*
 * Exercise 18.17: Write code to test your answers to the previous question.
 *
 * By Faisal Saadatmand
 */

/*
 * NOTE: comment or uncomment using declarations or the using directive to
 * the code.
*/

#include <iostream>

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
// position 1
void manip() {
	// position 2
	using Exercise::ivar;
	using Exercise::dvar;
	using Exercise::limit;
//	using namespace Exercise;

	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}

int main()
{
	manip();
	return 0;
}
