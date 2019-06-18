/*
 * Exercise 15.39: Implement the Query and Query_base classes. Test your
 * application by evaluating and printing a query such as the one in Figure
 * 15.3 (p. 638).
 *
 * By Faisal Saadatmand
 */

/*
 * This is the program to test the Query classes. Note that the buildQuery
 * function is optional.
 * */

#include <iostream>
#include <sstream>
#include <string>
#include "15.39.h"

// build queries using recursion
Query buildQuery(std::istringstream &iss, Query q)
{
	static bool highPrecednce = false;
	std::string op;
	if (!(iss >> op))
		return q;
	if (op == "&") {
		highPrecednce = true;
		q = q & buildQuery(iss, q); // give precedence to &
		return buildQuery(iss, q);  // then continue
	}
	if (op == "|")
		return q | buildQuery(iss, q);
	if (op[0] == '~') {
		op.replace(op.begin(), op.end(), op.substr(1));
		q = ~Query(op);
	} else
		q = Query(op);

	if (highPrecednce) {
		highPrecednce = false;
		return q;
	}
	return buildQuery(iss, q);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <filename>\n";
		return -1;
	}
	std::ifstream text(*++argv);
	if (!text) {
		std::cerr << "Couldn't open " << *argv << '\n';
		return -1;
	}
	TextQuery tq(text);
	std::string input;
	Query q;
	while (true) {
		if (!std::getline(std::cin, input) || input == "q")
			break;
		if (!input.empty()) {
			std::istringstream line(input);
			q = buildQuery(line, q);
			std::cout << q.eval(tq);
		}
	}
	return 0;
}
