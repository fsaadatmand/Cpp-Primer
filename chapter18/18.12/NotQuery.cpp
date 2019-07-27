#include <memory>
#include <set>
#include <string>
#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"

chapter15::NotQuery::NotQuery(const Query &q) : query(q) {}

namespace chapter15 {
chapter12::QueryResult
NotQuery::eval(const chapter12::TextQuery &text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return chapter12::QueryResult(rep(), ret_lines, result.get_file());
}

std::string
NotQuery::rep() const
{
	return "~(" + query.rep() + ")";
}
}
