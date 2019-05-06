/*
 * Exercise 9.47: Write a program that finds each numeric character and then
 * each alphabetic character in the string "ab2c3d7R4E6". Write two versions of
 * the program. The first should use find_first_of, and the second
 * find_first_not_of.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

int main()
{
	std::string s{"ab2c3d7R4E6"};
	std::string numbers{"0123456789"};
	std::cout << "string: " << s << '\n';
	for (decltype(s.size()) pos = 0; (pos = s.find_first_of(numbers, pos))
			!= std::string::npos; ++pos)
		std::cout << "found number at index: " << pos
			      << " element is " << s[pos] << '\n';
	for (decltype(s.size()) pos = 0; (pos = s.find_first_not_of(numbers, pos))
			!= std::string::npos; ++pos)
		std::cout << "found letter at index: " << pos
			      << " element is " << s[pos] << '\n';

	std::cout << '\n';

	std::string alphabets;
	alphabets.reserve(60);
	for (char c = 'a'; c <= 'z'; ++c) {
		alphabets.push_back(c);
		alphabets.push_back(toupper(c));
	}
	for (decltype(s.size()) pos = 0; (pos = s.find_first_not_of(alphabets, pos))
			!= std::string::npos; ++pos)
		std::cout << "found letter at index: " << pos
			      << " element is " << s[pos] << '\n';
	for (decltype(s.size()) pos = 0; (pos = s.find_first_of(alphabets, pos))
			!= std::string::npos; ++pos)
		std::cout << "found letter at index: " << pos
			      << " element is " << s[pos] << '\n';
	return 0;
}

