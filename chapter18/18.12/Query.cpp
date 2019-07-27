#include <ostream>
#include <string>
#include "Query.h"

namespace chapter15 {
Query::Query(std::shared_ptr<Query_base> query) : q(query) {}

chapter12::QueryResult
Query::eval(const chapter12::TextQuery &t) const { return q->eval(t); }

std::string
Query::rep() const { return q->rep(); }

std::ostream&
operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}
}
