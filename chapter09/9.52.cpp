/*
 * Exercise 9.52: Use a stack to process parenthesized expressions. When you
 * see an open parenthesis, note that it was seen. When you see a close
 * parenthesis after an open parenthesis, pop elements down to and including
 * the open parenthesis off the stack. push a value onto the stack to indicate
 * that a parenthesized expression was replaced.
 *
 * by Faisal Saadatmand
 */

#include <iostream>
#include <deque>
#include <stack>
#include <string>

int main()
{
	std::deque<int> deq;
	std::stack<int> stk(deq); 
	bool open = false;
	std::string line;
	while (getline(std::cin, line)) {
		for (auto ch = line.begin(); ch != line.end(); ++ch) {
			stk.push(*ch);
			if (*ch == '(')
				open = true;
			if (open && *ch == ')') {
				while (stk.top() != '(')
					stk.pop();
				stk.pop();          // pop remaining '(' char
				stk.push('*');      // indicator
				open = false;
			}
		}
		stk.push('\n');             // push removed newline char by for loop
	}
	// reverse stack
	std::deque<int> deqPrint;
	while (!stk.empty()) {
		deqPrint.push_front(stk.top());
		stk.pop();
	}
	// print reversed stack
	for (const auto &elem : deqPrint)
		std::cout << static_cast<char>(elem);
	std::cout << '\n';
	return 0;
}
