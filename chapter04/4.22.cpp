/*
 * Exercise 4.22: Extend the program that assigned high pass, pass, and fail
 * grades to also assign low pass for grades between 60 and 75 inclusive. Write
 * two versions: One version that uses only conditional operators; the other
 * should use one or more if statements. Which version do you think is easier
 * to understand and why?
 *
 * Answer: about the same, provided that you are comfortable with both
 * statements. That being said, anything beyond 3 nested conditional operators
 * could become quite illegible.
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	int grade;
	std::cin >> grade;
//	std::string finalgrade = (grade > 90) ? "high pass"
//		                   : (grade >= 65 && grade <= 75) ? "low pass"
//						   : (grade < 60) ? "fail" : "pass";

	std::string finalgrade = (grade > 90) ? "high pas" : (grade < 60) ? "fail" : "pass";
	std::cout << finalgrade << '\n';

	if (grade > 90)
		std::cout << "high pass\n";
	else if (grade >= 65 && grade<= 75)
		std::cout << "low pass\n";
	else
		std::cout << ((grade < 60) ? "fail\n" : "pass\n");


	return 0;
}
