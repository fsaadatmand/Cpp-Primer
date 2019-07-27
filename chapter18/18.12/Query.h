#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include "Query_base.h"
#include "QueryResult.h"
#include "WordQuery.h"
#include "QueryHistory.h"

class QueryHistory;
class TextQuery;
namespace chapter15 {
class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
	friend std::ostream& operator<<(std::ostream &, const Query &);
	public:
		Query() = default;
		Query(const std::string &);
		chapter12::QueryResult eval(const chapter12::TextQuery &t) const;
		std::string rep() const;
	private:
		Query(std::shared_ptr<Query_base> query);
		std::shared_ptr<Query_base> q;
};

inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {}

std::ostream& operator<<(std::ostream &, const Query &);
Query buildQuery(std::stringstream &, Query, const QueryHistory &);
std::stringstream& putback_str(std::stringstream &, const std::string &);
}
#endif
