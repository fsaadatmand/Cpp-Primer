
/*
 * Exercise 5.5: Using an if–else statement, write your own version of the
 * program to generate the letter grade from a numeric grade.
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
		if (grade < 60)
			lettergrade = scores[0];
		else {
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100) {
				if (grade % 10 > 7)
					lettergrade += '+';
				else if (grade % 10 < 3)
					lettergrade += '-';
			}

		}
		std::cout << lettergrade + '\n';
	}
	return 0;
}
