/*
 * Exercise 15.42: Design and implement one of the following enhancements:
 *
 *	(a) Print words only once per sentence rather than once per line.
 *	(b) Introduce a history system in which the user can refer to a previous
 *		query by number, possibly adding to it or combining it with another.
 *	(c) Allow the user to limit the results so that only matches in a given
 *		range of lines
 *
 * By Faisal Saadatmand
 */

/*  This is the solution for c. Note: the buildQuery function is optional. */

#include <exception>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include "15.39.h"  // Query and TextQuery
#include <vector>

class QueryHistory {
	public:
		Query& operator[](const std::size_t) const;
		void add(const Query &); 
		void list() const;
	private:
		std::vector<std::shared_ptr<Query>> history;
};

Query&
QueryHistory::operator[](const std::size_t n) const
{
	if (n > history.size())
		throw std::invalid_argument("invalid input");
	return *(history[n - 1]);
}

void
QueryHistory::add(const Query &q) 
{
	auto pq = std::make_shared<Query>(q);
	history.push_back(pq);
}

void
QueryHistory::list() const
{
	if (!history.size()) {
		std::cerr << "Empty history\n";
		return;
	}
	size_t i = 1;
	for (const auto &elem : history) {
		std::cout << i++ << ": " << elem->rep() << '\n';
	}
}

// build queries using recursion
Query buildQuery(std::istringstream &iss, Query query,
		const QueryHistory &history)
{
	static bool highPrecednce = false;
	std::string op;
	if (!(iss >> op))  // exist condition
		return query;

	if (op == "&") {
		highPrecednce = true;
		query = query & buildQuery(iss, query, history); // give precedence to &
		return buildQuery(iss, query, history);  // then continue with recursion
	}

	if (op == "|")
		return query | buildQuery(iss, query, history);
	if (op[0] == '~')
		query = ~Query(op.substr(1));
	else if (op[0] == '$')
		query = history[stoi(op.substr(1))]; // fetch string
	else
		query = Query(op);

	if (highPrecednce) {
		highPrecednce = false;
		return query;
	}
	return buildQuery(iss, query, history);
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
	std::string input, operand;
	Query query;
	QueryHistory history;
	while (true) {
		if (!std::getline(std::cin, input) || input == "q")
			break;
		else if (input == "$") { // list history
			history.list();
			continue;
		}
		if (!input.empty()) {
			try {
				std::istringstream line(input);
				query = buildQuery(line, query, history);
				history.add(query);
				std::cout << query.eval(tq);
			} catch (std::invalid_argument &err) {
				std::cerr << err.what() << '\n';
			}
		}
	}
	return 0;
}
