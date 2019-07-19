/*
 * Exercise 17.13: Write an integral object that contains the correct answers
 * for the true/false quiz. Use it to generate grades on the quiz for the data
 * structure from the previous two exercises
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <bitset>
#include <string>

struct Quiz {
	// added constructors to make initialization easier
	Quiz() = default;
	Quiz(const std::string &s) : answers(s) {}
	void set_answer(const std::size_t n, const bool value)
								{ answers.set(n, value); }
	constexpr std::size_t size() const { return quiz_size; }
	static constexpr std::size_t quiz_size = 100;
	std::bitset<quiz_size> answers;
};

unsigned gradeQuiz(const Quiz &key, const Quiz &quiz)
{
	unsigned grade = 0;
	for (decltype(key.size()) i = 0; i < key.size(); ++i)
		if (key.answers[i] == quiz.answers[i])
			++grade;
	return grade;
}

int main()
{
	// correct answers
	Quiz key("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	// a given student answer
	Quiz quiz("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110000000000");
	std::cout << gradeQuiz(key, quiz) << '\n';
	return 0;
}
