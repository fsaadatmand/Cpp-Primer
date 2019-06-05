/*
 * Exercise 13.44: Write a class named String that is a simplified version of
 * the library string class. Your class should have at least a default
 * constructor and a constructor that takes a pointer to a C-style string. Use
 * an allocator to allocate memory that your String class uses.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <cstring>

class String {
	friend std::ostream& print(std::ostream &, const String &);
	public:
		String() = default;
		String(const char *);
		String(const String &);
		String& operator=(const String &);
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

// copy controls
String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
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

int main()
{
	String s("this is a string");
	s.resize(20, 'c');
	std::cout << s.size() << '\n';
	std::cout << s.capacity() << '\n';
	print(std::cout, s) << '\n';
	return 0;
}
