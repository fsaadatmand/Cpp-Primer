/*
 * Exercise 5.9: Write a program using a series of if statements to count the
 * number of vowels in text read from cin.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

int main()
{
	int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char c;

	while (std::cin >> c)
		if (c == 'a' || c == 'A')
			++aCnt;
		else if (c == 'e' || c == 'E')
			++eCnt;
		else if (c == 'i' || c == 'I')
			++iCnt;
		else if (c == 'o' || c == 'O')
			++oCnt;
		else if (c == 'u' || c == 'U')
			++uCnt;

	std::cout << "Number of vowel a: \t" << aCnt << '\n'
		      << "Number of vowel e: \t" << eCnt << '\n'
			  << "Number of vowel i: \t" << iCnt << '\n'
			  << "Number of vowel o: \t" << oCnt << '\n'
			  << "Number of vowel u: \t" << uCnt << '\n'
			  <<"Total numer of vowels: \t" 
		      << aCnt + eCnt + iCnt + oCnt + uCnt << '\n';

	return 0;
}
