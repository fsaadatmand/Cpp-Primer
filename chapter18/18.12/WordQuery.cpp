#include <string>
#include "WordQuery.h"
#include "QueryResult.h"

namespace chapter15 {
WordQuery::WordQuery(const std::string &s) : query_word(s) {}

chapter12::QueryResult
WordQuery::eval(const chapter12::TextQuery &t) const
						{ return t.query(query_word); }

std::string
WordQuery::rep() const { return query_word; }
}
