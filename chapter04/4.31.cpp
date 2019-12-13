/*
 * Exercise 4.31: The program in this section used the prefix increment and
 * decrement operators. Explain why we used prefix and not postfix. What
 * changes would have to be made to use the postfix versions? Rewrite the
 * program using postfix operators.
 * 
 *
 * By Faisal Saadatmand
 */

/* Answer:
 * The postfix increment and decrement operators involve extra work. They
 * return a copy of the original (unchanged) value and then increment or
 * decrement their operand. This creates an unnecessary overhead in this
 * example, since we only need to increment ix and decrement cnt after the body
 * of the loop has been evaluated. 
 *
 * That said, to use the postfix increment and decrement operators instead, we
 * just need to rewrite the loop expression with the postfix increment and
 * decrement operators (see program below). Alternately, we could omit the loop
 * expression altogether and use the postfix operator in the body of the loop
 * to increment ix and decrement cnt:
 *
 * 		for(vector<int::size_type ix = 0; ix != ivec.size(); )
 * 			ivec[ix++] = cnt--;
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
		cout << ' ' << element;
	cout << '\n';
	return 0;
}
