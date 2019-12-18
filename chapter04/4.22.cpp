/*
 * Exercise 4.22: Extend the program that assigned high pass, pass, and fail
 * grades to also assign low pass for grades between 60 and 75 inclusive. Write
 * two versions: One version that uses only conditional operators; the other
 * should use one or more if statements. Which version do you think is easier
 * to understand and why?
 *
 * By Faisal Saadatmand
 */

/*
 * Answer: about the same, provided that you are comfortable with both
 * approaches. That being said, anything beyond 3 nested conditional operators
 * could become quite illegible.
 */
 
// conditional operators version. See 4.22a.cpp for the if statements version.
//
#include <iostream>
#include <string>

int main()
{
	int grade;
	std::cin >> grade;
	std::string finalgrade = (grade > 90) ? "high pass"
		                   : (grade > 75) ? "pass"
						   : (grade >= 60 && grade <= 75) ? "low pass"
						   : "fail";
	std::cout << finalgrade << '\n';
	return 0;
}
