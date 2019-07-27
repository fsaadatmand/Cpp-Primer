#ifndef BUILD_QUERY_H
#define BUILD_QUERY_H

#include <sstream>
#include <string>
#include "Query.h"
#include "QueryHistory.h"

namespace chapter15 {
Query buildQuery(std::stringstream &, const QueryHistory &);
std::stringstream& putback_str(std::stringstream &, Query query, const std::string &);
}
#endif
