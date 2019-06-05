/*
 * Exercise 13.39: Write your own version of StrVec, including versions of
 * reserve, capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).
 *
 * By Faisal Saadatmand
 */

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>

class StrVec {
	public:
		StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
		StrVec(const StrVec &);
		StrVec& operator=(const StrVec &);
		~StrVec() { free(); }
		void push_back(const std::string &);
		size_t size() const { return first_free - elements; }
		size_t capacity() const { return cap - elements; }
		std::string *begin() const { return elements; }
		std::string *end() const { return first_free; }
		void reserve(const size_t &);
		void resize(const size_t &, const std::string &s = "");
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

// static members
std::allocator<std::string> StrVec::alloc;

// copy-control functions
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec&
StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

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

int main()
{
	StrVec svec;
	std::string word;

	svec.reserve(100);
	std::cout << svec.size() << '\n';
	std::cout << svec.capacity() << '\n';

	while (std::cin >> word)
		svec.push_back(word);

	svec.resize(58, "zero");
	for (const auto &elem : svec)
		std::cout << elem << '\n';
	std::cout << svec.size() << '\n';
	std::cout << svec.capacity() << '\n';

	return 0;
}
