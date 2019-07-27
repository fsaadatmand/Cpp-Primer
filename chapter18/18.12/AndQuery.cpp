#include <algorithm>
#include <iterator>
#include <memory>
#include <iterator>
#include "AndQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"

namespace chapter15 {
AndQuery::AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}

chapter12::QueryResult
AndQuery::eval(const chapter12::TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(),
			right.begin(), right.end(),
			std::inserter(*ret_lines, ret_lines->begin()));
	return chapter12::QueryResult(rep(), ret_lines, left.get_file());
}
}
