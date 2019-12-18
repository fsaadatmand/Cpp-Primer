/*
 * Exercise 4.22: Extend the program that assigned high pass, pass, and fail
 * grades to also assign low pass for grades between 60 and 75 inclusive. Write
 * two versions: One version that uses only conditional operators; the other
 * should use one or more if statements. Which version do you think is easier
 * to understand and why?
 *
 * By Faisal Saadatmand
 */

// if statements version.

#include <iostream>
#include <string>

int main()
{
	int grade;
	std::cin >> grade;
	std::string finalgrade = (grade > 90) ? "high pass"
		                   : (grade < 60) ? "fail"
						   : "pass";
	if (grade >= 60 && grade<= 75)
		finalgrade = "low pass";
	std::cout << finalgrade << '\n';
	return 0;
}
