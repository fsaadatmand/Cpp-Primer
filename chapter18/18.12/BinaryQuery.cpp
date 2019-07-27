#include "BinaryQuery.h"

namespace chapter15 {
BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s) :
			lhs(l), rhs(r), opSym(s) {}

std::string
BinaryQuery::rep() const
		{ return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
}
