
/*
 * Exercise 5.11: Modify our vowel-counting program so that it also counts the
 * number of blank spaces, tabs, and newlines read.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
			 tabCnt = 0, spCnt = 0, nwCnt = 0;
	
	char ch;
	std::string line;

	while (getline(std::cin, line)) {  // use getline as not to skip whitespaces
		line += '\n';                  // add back discarded newline char
		auto it = line.begin();
		while ((ch = *it++)) {         // scan the string
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
		<< "Number of newlines: \t" << nwCnt << std::endl;
	return 0;
}
