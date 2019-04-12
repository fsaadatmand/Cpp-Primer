/*
 * Exercise 5.6: Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
	std::string lettergrade;
	int grade;

	while (std::cin >> grade) {
		lettergrade = (grade < 60) ? scores[0] 
			                       : (grade == 100) ? scores[(grade - 50) / 10]
								   : (grade % 10 > 7) ? scores[(grade - 50) / 10] + '+'
								   : (grade % 10 < 3) ? scores[(grade - 50) / 10] + '-'
								   : scores[(grade - 50) / 10];
		std::cout << lettergrade + '\n';
	}
	return 0;
}

