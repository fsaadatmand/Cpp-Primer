/*
 * Exercise 15.37: What changes would your classes need if the derived classes
 * had members of type shared_ptr<Query_base> rather than of type Query?
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <string>
#include "TextQuery.h"

class Query_base {
	friend class Query;
	protected:
		using line_no = TextQuery::line_no; 
		virtual ~Query_base() = default;
	public:  // changed to public from private
//		virtual QueryResult eval(const TextQuery &) const = 0;
		virtual std::string rep() const = 0;
};

class Query {
	friend std::shared_ptr<Query_base>
		operator~(const std::shared_ptr<Query_base> &);
	friend std::shared_ptr<Query_base>
		operator|(const std::shared_ptr<Query_base> &,
				const std::shared_ptr<Query_base> &);
	friend std::shared_ptr<Query_base>
		operator&(const std::shared_ptr<Query_base> &,
				const std::shared_ptr<Query_base> &);
	friend std::ostream& operator<<(std::ostream &, const Query &);
	public:
		Query(const std::string &);
//		QueryResult eval(const TextQuery &t) const { return q->eval(t); }
		std::string rep() const
		{ std::cout << "Query::rep()\n"; return q->rep(); }
		operator std::shared_ptr<Query_base>() { return q; } // conversion operator
		Query(std::shared_ptr<Query_base> query) : q(query)
		{ std::cout << "Query(std::shared_ptr<Query_base>)\n"; }
	private:
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
	WordQuery(const std::string &s) : query_word(s)
	{ std::cout << "WordQuery(const std::string &)\n"; }
//	QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
	std::string rep() const override
	{ std::cout << "WordQuery::rep()\n"; return query_word; };
	std::string query_word;
};

// Query constructor, needs WordQuery definition
inline
Query::Query(const std::string &s) : q(new WordQuery(s))
			{ std::cout << "Query(const std::string &)\n"; }

class NotQuery : public Query_base {
	friend std::shared_ptr<Query_base>
		operator~(const std::shared_ptr<Query_base> &);
	NotQuery(const std::shared_ptr<Query_base> &q) : query(q) {}
	std::string rep() const override
	{ std::cout << "NotQuery::rep()\n"; return "~(" + query->rep() + ")"; }
//	QueryResult eval(const TextQuery &) const;
	std::shared_ptr<Query_base> query;

};

inline
std::shared_ptr<Query_base>operator~(const std::shared_ptr<Query_base> &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
	protected:
		BinaryQuery(const std::shared_ptr<Query_base> &l,
				const std::shared_ptr<Query_base> &r, std::string s) :
			lhs(l), rhs(r), opSym(s)
	{ std::cout << "BinaryQuery(const Query &, const Query &, std::string &)\n"; }
		std::string rep() const override;
		std::shared_ptr<Query_base> lhs, rhs;
	std::string opSym;
};

std::string
BinaryQuery::rep() const
{
	std::cout << ((opSym == "&") ? "AndQuery::rep();" : "OrQuery;") << '\n';
	return "(" + lhs->rep() + " " + opSym + " " + rhs->rep() + ")"; 
}
class AndQuery : public BinaryQuery {
	friend std::shared_ptr<Query_base>
		operator&(const std::shared_ptr<Query_base> &,
				const std::shared_ptr<Query_base> &);
	AndQuery(const std::shared_ptr<Query_base> &left,
			const std::shared_ptr<Query_base> &right) :
		BinaryQuery(left, right, "&")
	{ std::cout << "AndQuery(const Query &, const Query &)\n"; } 
//	QueryResult eval (const TextQuery &) const;
};

inline
std::shared_ptr<Query_base>
operator&(const std::shared_ptr<Query_base> &lhs,
		const std::shared_ptr<Query_base> &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
	friend std::shared_ptr<Query_base>
		operator|(const std::shared_ptr<Query_base> &,
				const std::shared_ptr<Query_base> &);
	OrQuery(const std::shared_ptr<Query_base> &left,
			const std::shared_ptr<Query_base> &right) :
		BinaryQuery(left, right, "|")
	{ std::cout << "OrQuery(const Query &, const Query &)\n"; } 
//	QueryResult eval (const TextQuery &) const;
};

inline
std::shared_ptr<Query_base>
operator|(const std::shared_ptr<Query_base> &lhs,
		const std::shared_ptr<Query_base> &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main()
{
	Query p = Query("fiery") & Query("bird") | Query("wind");
	std::cout << "\n";
	std::cout << p << '\n';
	return 0;
}
