#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include <string>
#include "TextQuery.h"

namespace chapter15 {
class Query_base {
	friend class Query;
	protected:
		using line_no = chapter12::TextQuery::line_no; 
		virtual ~Query_base() = default;
	private:
		virtual chapter12::QueryResult
			eval(const chapter12::TextQuery &) const = 0;
		virtual std::string rep() const = 0;
};
}
#endif
