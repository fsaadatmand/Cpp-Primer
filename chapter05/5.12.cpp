/*
 * Exercise 5.12: Modify our vowel-counting program so that it counts the
 * number of occurrences of the following two-character sequences: ff, fl, and
 * fi.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
			 tabCnt = 0, spCnt = 0, nwCnt = 0,
			 ffCnt = 0, flCnt = 0, fiCnt = 0;
	
	char ch;
	std::string line;

	while (getline(std::cin, line)) {  // use getline as not to skip whitespaces
		line += '\n';                  // add back discarded newline char
		auto it = line.begin();
		while ((ch = *it++)) {
			switch (tolower(ch)) {
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
			case '\t':
				++tabCnt;
				break;
			case ' ':
				++spCnt;
				break;
			case '\n':
				++nwCnt;
			case 'f':
				switch (*it) {         // peak at the next char
				case 'f':
					++ffCnt;
					break;
				case 'l':
					++flCnt;
					break;
				case 'i':
					++fiCnt;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
	}
	std::cout << "Number of vowel a: \t" << aCnt << '\n'
		<< "Number of vowel e: \t" << eCnt << '\n'
		<< "Number of vowel i: \t" << iCnt << '\n'
		<< "Number of vowel o: \t" << oCnt << '\n'
		<< "Number of vowel u: \t" << uCnt << '\n'
		<< "Number of tabs: \t" << tabCnt << '\n'
		<< "Number of spaces: \t" << spCnt << '\n'
		<< "Number of newlines: \t" << nwCnt << '\n'
		<< "Number of ff: \t" << ffCnt << '\n'
		<< "Number of fl: \t" << flCnt << '\n'
		<< "Number of fi: \t" << fiCnt << std::endl;
	return 0;
}
