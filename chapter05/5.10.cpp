
/*
 * Exercise 5.10: There is one problem with our vowel-counting program as we've
 * implemented it: It doesn't count capital letters as vowels. Write a program
 * that counts both lower- and uppercase letters as the appropriate vowel—that
 * is, your program should count both ’a’ and ’A’ as part of aCnt, and so
 * forth.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;

	while (std::cin >> ch) {
		switch (tolower(ch)) {    // simplest way is to convert all char
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		default:
			break;
		}
	}
	std::cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << std::endl;
	return 0;
}
