#include <exception>
#include <iostream>
#include <memory>
#include "QueryHistory.h"
#include "Query.h"

namespace chapter15 {
Query&
QueryHistory::operator[](const std::size_t n) const
{
	if (n > history.size())
		throw std::invalid_argument("invalid input");
	return *(history[n - 1]);
}

void
QueryHistory::add(const Query &q) 
{
	auto pq = std::make_shared<Query>(q);
	history.push_back(pq);
}

void
QueryHistory::list() const
{
	if (!history.size()) {
		std::cerr << "Empty history\n";
		return;
	}
	size_t i = 1;
	for (const auto &elem : history)
		std::cout << i++ << ": " << elem->rep() << '\n';
}
}
