/*
 * Exercise 13.49: Add a move constructor and move-assignment operator to your
 * StrVec, String, and Message classes.
 *
 * By Faisal Saadatmand
 */

#ifndef FS_STRING_H
#define FS_STRING_H

#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

class String {
	friend std::ostream& print(std::ostream &, const String &);
	public:
		String() = default;
		String(const char *);
		String(const String &);
		String(String &&) noexcept;
		String& operator=(const String &);
		String& operator=(String &&) noexcept;
		~String() { free(); }
		void push_back(const char &);
		void pop_back();
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		char *begin() const { return elements; }
		char *end() const { return first_free; }
		void reserve(const size_t &n) { if (n > capacity()) reallocate(n); }
		void resize(const size_t &, const char &ch = '\0');
	private:
		static std::allocator<char> alloc;
		void chk_n_alloc() { if (size() == capacity()) reallocate(); }
		std::pair<char *, char *> alloc_n_copy(const char *, const char *);
		void reallocate(const size_t &n = 0);
		void free();
		char *elements{nullptr};
		char *first_free{nullptr};
		char *cap{nullptr};
};

// static members
std::allocator<char> String::alloc;

// constructors
String::String(const char *s)
{
	auto data = alloc_n_copy(s, s + std::strlen(s));
	elements = data.first; 
	first_free = cap = data.second;
}

// copy-controls functions
String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(String &&s) noexcept : elements(s.elements),
	first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = cap = nullptr;
}

String&
String::operator=(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

String&
String::operator=(String &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		elements = first_free = cap = nullptr;
	}
	return *this;
}

// member functions
void
String::push_back(const char &ch)
{
	chk_n_alloc();
	alloc.construct(first_free++, ch);
}

void
String::pop_back()
{
	if (first_free == elements)
		throw std::out_of_range("pop on empty String");
	alloc.destroy(--first_free);
}

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e - b);
	return {data, std::uninitialized_copy(b, e, data)};
}

void
String::reallocate(const size_t &n)
{
	auto newcapacity = (n) ? n : (size()) ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void
String::free()
{
	for (auto &p = first_free; p != elements;)
		alloc.destroy(--p);
	alloc.deallocate(elements, capacity());
}

void
String::resize(const size_t &n, const char &ch)
{
	reserve(n);
	auto newsize = first_free + (n - size());
	while (first_free != newsize)
		if (first_free < newsize)
			alloc.construct(first_free++, ch);
		else
			alloc.destroy(--first_free);
}

// non-member functions
std::ostream& print(std::ostream &os, const String &s)
{
	for (const auto &ch : s)
		os << ch; 
	return os;
}
#endif