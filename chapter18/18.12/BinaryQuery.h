#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "Query_base.h"
#include "Query.h"

namespace chapter15 {
class BinaryQuery : public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s);
		std::string rep() const override;
	Query lhs, rhs;
	std::string opSym;
};
}
#endif

