/*
 * Exercise 1.6: Explain whether the following program fragment is legal
 *
	 * std::cout << "The sum of " << v1;
	 * << " and " << v2;
	 * << " is " << v1 + v2 << std::endl;
	 *
 * If the program is legal, what does it do? If the program is not legal, why
 * not? How would you fix it?
 *
 *
 * Answer: it is not legal. Semicolons are used to end statements: line 1 is
 * fine but line 2 and 3 are not complete statements. Remove semicolons at the
 * end of line one and line 2, or add std::cout at the beginning of line 2 and
 * 3, to fix the fragment. Also, v1 and v2 need to be declared and initialized.
 *
 * by Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int v1 = 1, v2 = 4;
	std::cout << "The sum of " << v1
	<< " and " << v2
	<< " is " << v1 + v2 << std::endl;
	return 0;
}

	 
