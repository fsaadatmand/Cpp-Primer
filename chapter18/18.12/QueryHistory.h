#ifndef QUERY_HISTORY_H
#define QUERY_HISTORY_H

#include <sstream>
#include <string>
#include <memory>
#include "Query.h"
#include "vector"

namespace chapter15 {
class Query;
class QueryHistory {
	public:
		Query& operator[](const std::size_t) const;
		void add(const Query &); 
		void list() const;
	private:
		std::vector<std::shared_ptr<Query>> history;
};

std::stringstream& putback_str(std::stringstream &, const std::string &);
}
#endif
