/*
 * Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p. 224) a
 * default argument of 's'. Test your program by printing singular and plural
 * versions of the words success and failure.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

// return the plural version of word if ctr is greater than 1
inline std::string make_plural(size_t ctr, const std::string &word,
		                            const std::string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main() {
	std::string word{"computer"};
	std::cout << make_plural(2, word) << '\n';
	return 0;
}
