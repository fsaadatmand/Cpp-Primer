#include <sstream>
#include <string>
#include "buildQuery.h"
#include "Query.h"
#include "QueryHistory.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

namespace chapter15 {
Query buildQuery(std::stringstream &ss, Query query, const QueryHistory &history)
{
	static bool recurseOnce = false;
	std::string op;

	if (!(ss >> op))  // exit condition
		return query;

	if (op == "&") {
		recurseOnce = true;
		query = query & buildQuery(ss, query, history); // give precedence to &
		recurseOnce = false;
		return buildQuery(ss, query, history); // continue with normal recursion
	}

	if (op == "|")
		return query | buildQuery(ss, query, history);

	if (op[0] == '~') {
		putback_str(ss, op.substr(1));
		return ~buildQuery(ss, query, history);
	}

	if (op[0] == '$') // history command prefix
		query = history[stoi(op.substr(1))]; // fetch history
	else
		query = Query(op);

	return (recurseOnce) ? query : buildQuery(ss, query, history);
}

// putback an entire string into stringstream in reverse order
std::stringstream& putback_str(std::stringstream &ss, const std::string &s)
{
	for (auto it = s.crbegin(); it != s.crend(); ++it)
		ss.putback(*it);
	return ss;
}
}
