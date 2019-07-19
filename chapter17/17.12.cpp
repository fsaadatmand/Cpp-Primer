/*
 * Exercise 17.12: Using the data structure from the previous question, write a
 * function that takes a question number and a value to indicate a true/false
 * answer and updates the quiz results accordingly.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <bitset>

struct Quiz {
	void set_answer(const std::size_t n, const bool value)
								{ answers.set(n, value); }
	static constexpr size_t quiz_size = 100;
	std::bitset<quiz_size> answers;
};

int main()
{
	Quiz quiz;
	quiz.set_answer(1, true);
	std::cout << quiz.answers << '\n';
	return 0;
}
