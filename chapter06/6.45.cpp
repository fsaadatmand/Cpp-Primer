/*
 * Exercise 6.45: Review the programs you’ve written for the earlier exercises
 * and decide whether they should be defined as inline. If so, do so. If not,
 * explain why they should not be inline.
 * 
 *
 * By Faisal Saadatmand
 */

/*
 * Answer: most functions could be converted to inline, provided that they are
 * non-recursive and are short enough (less than 75 lines) to be expanded,
 * otherwise the compiler will definitely ignore the inline. Below are a few
 * examples from this chapter of such functions.
 */

#include <iostream>
#include <string>

inline int compareInt(const int i, const int *j)
{
	return (!j || i > *j) ? i : *j;
}

inline bool isAnyUpper(const std::string &s)
{
	bool result = false;

	for (const auto &c : s)
		if (isupper(c)) {
			result = true;
			break;
		}

	return result;
}

inline void tolowerS(std::string &s)
{
	for (auto &c : s)
		if (isupper(c))
			c = tolower(c);
}

inline void print(const int *s)
{
	if (!s)
		return;
	while (*s)
		std::cout << *s++;
}

inline void print(const int *start, const int *end)
{
	while (start != end)
		std::cout << *start++ << '\n';
}

inline void print(const int a[], size_t size)
{
	for (size_t i = 0; i != size; ++i)
		std::cout << a[i] << '\n';
}

inline void print(const int (&a)[2])
{
	for (auto element : a)
		std::cout << element << '\n';
}

int main()
{
	int x = 20;
	const int y = 42;
	
	std::cout << compareInt(x, &y) << '\n';

	std::string str{"This a Test sTrnig"};
	std::cout << isAnyUpper(str) << '\n';
	std::cout << str << '\n';
	tolowerS(str);
	std::cout << str << '\n';

	int i = 0, j[2] = {0, 1};
	int *pi = &i;
	int (&rj)[2] = j;

	print(pi, pi + 1);
	print(&j[0], &j[2]);

	print(&i, 1);
	print(j, 2);

	print(rj);

	return 0;
}
