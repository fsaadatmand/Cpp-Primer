#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include <string>
#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"

namespace chapter15 {
class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s);
	chapter12::QueryResult
		eval(const chapter12::TextQuery &t) const override;
	std::string rep() const override;
	std::string query_word;
};
}
#endif
