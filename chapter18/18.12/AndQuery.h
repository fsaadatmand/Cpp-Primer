#ifndef AND_QUERY_H
#define AND_QUERY_H

#include <memory>
#include "BinaryQuery.h"
#include "Query.h"

class QueryResult;
class TextQuery;
namespace chapter15 {
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right);
	chapter12::QueryResult
		eval(const chapter12::TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
}
#endif
