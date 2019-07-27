#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "QueryResult.h"

namespace chapter12 {
class QueryResult;
class TextQuery {
	public:
		using line_no = std::vector<std::string>::size_type;
		TextQuery(std::ifstream &);
		QueryResult query(const std::string &) const;
	private:
		std::shared_ptr<std::vector<std::string>> file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

void excludePunctuation(std::string &);
void runQueries(std::ifstream &);
}
#endif
