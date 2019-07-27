#ifndef OR_QUERT_H
#define OR_QUERT_H

#include <memory>
#include "Query.h"
#include "BinaryQuery.h"

class TextQuery;
class QueryResult;
namespace chapter15 {
class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &, const Query &);
	chapter12::QueryResult
		eval(const chapter12::TextQuery &) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
}
#endif
