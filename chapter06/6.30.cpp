/*
 * Exercise 6.30: Compile the version of str_subrange as presented on page 223
 * to see what your compiler does with the indicated errors.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

bool str_subrange(const std::string &str1, const std::string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size) i = 0; i != size; ++i)
		if (str1[i] != str2[i])
			return;       // error: compiler detected it 
                          // error: compiler did not detect it
}

int main()
{

	return 0;
}
