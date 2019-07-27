#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include <memory>
#include <string>
#include "Query.h"
#include "Query_base.h"

class QueryResult;
class TextQuery;
namespace chapter15 {
class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q);
	chapter12::QueryResult
		eval(const chapter12::TextQuery &) const override;
	std::string rep() const override;
	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}
}
#endif
