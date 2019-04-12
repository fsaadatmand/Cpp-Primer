/*
 * Exercise 4.31: The program in this section used the prefix increment and
 * decrement operators. Explain why we used prefix and not postfix. What
 * changes would have to be made to use the postfix versions? Rewrite the
 * program using postfix operators.
 * 
 * The postfix operators involve extra work to return a copy of the original
 * value as an rvalue (unchanged value). Since this is unnecessary in our
 * example and given the fact that we are changing two objects in the loop
 * (incrementing ix and decrementing cnt), it is all the more reason to use the
 * prefix operators. To use the postfix instead we just need to rewrite loop
 * expression as ix++, cn--.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <vector>

int main()
{
	using std::cout; using std::vector;

	vector<int> ivec(10);
	vector<int>::size_type cnt = ivec.size();

	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
		ivec[ix] = cnt;

	for (auto &element : ivec)
		cout << element << " ";
	cout << '\n';

	return 0;
}
