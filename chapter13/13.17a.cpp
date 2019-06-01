/*
 * Exercise 13.17: Write versions of numbered and f corresponding to the
 * previous three exercises and check whether you correctly predicted the
 * output.
 *
 * By Faisal Saadatmand
*/

#include <iostream>

// no copy-control members version
struct Numbered {
	Numbered() { ++mysn; }
	unsigned mysn = 0;
};

void f(Numbered s) { std::cout << s.mysn << '\n'; }

int main()
{
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
