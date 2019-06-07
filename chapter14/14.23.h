/*
 * Exercise 14.23: Define an initializer_list assignment operator for your
 * version of the StrVec class.
 *
 * By Faisal Saadatmand
 */

#ifndef STR_VEC_H
#define STR_VEC_H

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec {
	friend bool operator==(const StrVec &, const StrVec &);
	friend bool operator!=(const StrVec &, const StrVec &);
	friend bool operator<(const StrVec &, const StrVec &);
	public:
		StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
		StrVec(std::initializer_list<std::string>);
		StrVec(const StrVec &);
		StrVec(StrVec &&) noexcept;  // move constructor
		StrVec& operator=(const StrVec &);
		StrVec& operator=(StrVec &&) noexcept; // move assignment operator
		~StrVec() { free(); }
		void push_back(const std::string &);
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		std::string *begin() const { return elements; }
		std::string *end() const { return first_free; }
		void reserve(const size_t &);
		void resize(const size_t &, const std::string &s = "");
		StrVec& operator=(std::initializer_list<std::string>);
	private:
		static std::allocator<std::string> alloc;
		void chk_n_alloc() { if (size() == capacity()) reallocate(); }
		std::pair<std::string *, std::string *>
			alloc_n_copy(const std::string *, const std::string *);
		void free();
		void reallocate(size_t n = 0);
		std::string *elements;
		std::string *first_free;
		std::string *cap;
};

// static member
std::allocator<std::string> StrVec::alloc;

// constructor
StrVec::StrVec(std::initializer_list<std::string> il) : StrVec()
{
	reallocate(il.size());
	for (auto p = il.begin(); p != il.end(); ++p)
		alloc.construct(first_free++, *p);
}

// copy-control functions
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	std::cout << "StrVec(const StrVec &)\n";
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements),
	first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = cap = nullptr;
	std::cout << "StrVec(StrVec &&)\n";
}

StrVec&
StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	std::cout << "StrVec& operator=(const StrVec &)\n";
	return *this;
}

StrVec&
StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	std::cout << "StrVec& operator=(StrVec &&)\n";
	return *this;
}

// member functions
void
StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

void
StrVec::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void
StrVec::reallocate(size_t n) // n is optional
{
	auto newcapacity = (n) ? n : (size()) ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;  // points to the next free pos in the new array
	auto elem = elements; // points to next element in the old array
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void
StrVec::reserve(const size_t &n)
{
	if (n > capacity()) // requested size is bigger than capacity
		reallocate(n);  // use optional argument
}

void
StrVec::resize(const size_t &n, const std::string &s)
{
	if (n > capacity())
		reallocate(n);
	auto newsize = first_free + (n - size());	// points to the new first_free
	while (first_free != newsize)
		if (first_free < newsize)
			alloc.construct(first_free++, s);
		else
			alloc.destroy(--first_free);
}

StrVec&
StrVec::operator=(std::initializer_list<std::string> il)
{
	for (const auto &str : il) 
		push_back(str);
	return *this;
}

// non-member functions
bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	bool result = false;
	if (lhs.size() == rhs.size()) {
		result = true;
		auto rhsP = rhs.elements;
		for (const auto &elem : lhs)
			if (elem != *rhsP++) {
				result = false;
				break;
			}
	}
	return result;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

// using dictionary ordering
bool operator<(const StrVec &lhs, const StrVec &rhs)
{
	if (lhs.size() == rhs.size()) {
		auto rhsP = rhs.begin();
		for (const auto &str : lhs) {
			if (str != *rhsP)
				return str < *rhsP;
			++rhsP;
		}
	}
	return lhs.size() < rhs.size();
}
#endif
