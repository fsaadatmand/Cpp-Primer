#include <iostream>
#include <memory>
#include "QueryResult.h"

namespace chapter12 {
QueryResult::QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
	sought(s), lines(p), file(f) {}

std::set<QueryResult::line_no>::iterator
QueryResult::begin() const { return lines->begin(); }

std::set<QueryResult::line_no>::iterator
QueryResult::end() const { return lines->end(); }

std::shared_ptr<std::vector<std::string>>
QueryResult::get_file() const { return file; }

std::string make_plural(std::size_t ctr, const std::string &word,
		                             const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream& operator<<(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") "
			<< (*qr.get_file())[num] << std::endl;  // use get_file instead
	}
	return os;
}
}
