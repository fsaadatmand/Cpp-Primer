/*
 * Exercise 15.39: Implement the Query and Query_base classes. Test your
 * application by evaluating and printing a query such as the one in Figure
 * 15.3 (p. 638).
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "TextQuery.h"
#include <utility>

class Query_base {
	friend class Query;
	protected:
		using line_no = TextQuery::line_no; 
		virtual ~Query_base() = default;
	private:
		virtual QueryResult eval(const TextQuery &) const = 0;
		virtual std::string rep() const = 0;
};

class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
	friend std::ostream& operator<<(std::ostream &, const Query &);
	public:
		Query(const std::string &);
		QueryResult eval(const TextQuery &t) const { return q->eval(t); }
		std::string rep() const { return q->rep(); }
	private:
		Query(std::shared_ptr<Query_base> query) : q(query) {}
		std::shared_ptr<Query_base> q;
};

std::ostream&
operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}

class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) {}
	QueryResult eval(const TextQuery &t) const override
	{ return t.query(query_word); }
	std::string rep() const override { return query_word; }
	std::string query_word;
};

// Query constructor, needs WordQuery definition
inline
Query::Query(const std::string &s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {}
	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	Query query;

};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult
NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery : public Query_base {
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s) :
			lhs(l), rhs(r), opSym(s) {}
		std::string rep() const override { return "(" + lhs.rep() + " "
												 + opSym + " "
												 + rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult
AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	std::set_intersection(left.begin(), left.end(),
			right.begin(), right.end(),
			std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult
OrQuery::eval(const TextQuery &text) const
{
	auto left = rhs.eval(text), right = lhs.eval(text);
	auto ret_lines =
		std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	return QueryResult(rep(), ret_lines, left.get_file());
}

int main()
{
	std::string file = "story.txt";
	std::ifstream text(file);
	if (!text) {
		std::cerr << "couldn't open " << file << '\n';
		return -1;
	}
	TextQuery tq(text);
	Query p = Query("fiery") | Query("bird") | Query("wind");
	std::cout << p.eval(tq);
	return 0;
}
