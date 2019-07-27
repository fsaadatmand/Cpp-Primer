#include <memory>
#include <set>
#include "OrQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"

namespace chapter15 {
OrQuery::OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}

chapter12::QueryResult
OrQuery::eval(const chapter12::TextQuery &text) const
{
	auto left = rhs.eval(text), right = lhs.eval(text);
	auto ret_lines =
		std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return chapter12::QueryResult(rep(), ret_lines, left.get_file());
}
}
