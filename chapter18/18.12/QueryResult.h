#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <memory>
#include <set>
#include <string>
#include <vector>

namespace chapter12 {
class QueryResult {
	friend std::ostream& operator<<(std::ostream &, const QueryResult &);
	public:
		using line_no = std::vector<std::string>::size_type;
		QueryResult(std::string s,
			        std::shared_ptr<std::set<line_no>> p,
					std::shared_ptr<std::vector<std::string>> f);
		std::set<line_no>::iterator begin() const;
		std::set<line_no>::iterator end() const;
		std::shared_ptr<std::vector<std::string>> get_file() const;
	private:
		std::string sought;
		std::shared_ptr<std::set<line_no>> lines;
		std::shared_ptr<std::vector<std::string>> file;
};

std::string make_plural(std::size_t, const std::string &,
		                             const std::string &);
std::ostream& operator<<(std::ostream &, const QueryResult &);
}
#endif
