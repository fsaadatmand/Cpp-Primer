/*
 * Exercise 15.41: Reimplement your classes to use built-in pointers to
 * Query_base rather than shared_ptrs. Remember that your classes will no
 * longer be able to use the synthesized copy-control members.
 *
 * By Faisal Saadatmand
 */

/*
 * Since we cannot copy the value pointed to by the Query_base pointer
 * directly, we must use a pointer-like behaviour for our classes. (p. 513-516)
 * The easiest way to implement this is by using a reference-counter.  (ibid.)
 * Furthermore, if we keep the Query class as the interface through which users
 * interact with the inheritance hierarchy, then we only need to change that
 * class and the return value of the overloaded operators &, | and ~. It is
 * noteworthy to mention that their return value need not be cast to
 * Query_base* because the Query constructor that takes Query_base* also
 * accepts objects of the derived classes because of the derived-to-base
 * conversion.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include "TextQuery.h"

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
		Query(const Query &query) : q(query.q), use(query.use) { ++*use; }
		Query(Query &&query) noexcept;
		Query& operator=(const Query &); // copy-assignment operator
		Query& operator=(Query &&) noexcept; // move-assignment operator
		Query(const std::string &);
		QueryResult eval(const TextQuery &t) const { return q->eval(t); }
		std::string rep() const { return q->rep(); }
		~Query(); // destructor
	private:
		Query(Query_base *query) : q(query), use(new std::size_t(1)) {}
		Query_base *q;
		std::size_t *use;
};

Query::Query(Query &&query) noexcept : q(query.q), use(query.use)
{
	++*use; ;
	query.q = nullptr;
}

Query&
Query::operator=(const Query &rhs)
{
	++*rhs.use;
	if(!--*use) {
		delete q;
		delete use;
	}
	q = rhs.q;
	use = rhs.use;
	return *this;
}

Query&
Query::operator=(Query &&rhs) noexcept
{
	if (this != &rhs) {
		++*rhs.use;
		if (!--*use) {
			delete q;
			delete use;
		}
		q = rhs.q;
		use = rhs.use;
		rhs.q = nullptr;
		rhs.use = nullptr;
	}
	return *this;
}

Query::~Query()
{
	if (!--*use) {
		delete q;
		delete use;
	}
}

std::ostream& operator<<(std::ostream &os, const Query &query)
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
Query::Query(const std::string &s) :
	q(new WordQuery(s)), use(new std::size_t(1)) {}

class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {}
	QueryResult eval(const TextQuery &) const override;
	std::string rep() const override { return "~(" + query.rep() + ")"; }
	Query query;
};

inline Query operator~(const Query &operand)
{
	return new NotQuery(operand);
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
		std::string rep() const override
		{ return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }
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
	return new AndQuery(lhs, rhs);
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
	return new OrQuery(lhs, rhs);
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
	Query p = Query("fiery") & Query("bird") | Query("wind");
	std::cout << p.eval(tq);
	return 0;
}
