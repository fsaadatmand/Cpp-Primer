/*
 * Exercise 14.28: Define addition and subtraction for StrBlobPtr so that these
 * operators implement pointer arithmetic (§ 3.5.3, p. 119).
 *
 * By Faisal Saadatmand
 */

#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
	friend bool operator==(const StrBlob &, const StrBlob &);
	friend bool operator!=(const StrBlob &, const StrBlob &);
	friend bool operator<(const StrBlob &, const StrBlob &);
	public:
		friend class StrBlobPtr;
		using size_type = std::vector<std::string>::size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		StrBlob(const StrBlob &rhs) :          // copy constructor 
			data(std::make_shared<std::vector<std::string>> (*rhs.data)) { }
		StrBlob& operator=(const StrBlob &);   // copy assignment operator
		StrBlobPtr begin() const;  // return StrBlobPtr to the first element
		StrBlobPtr end() const;    // and one past the last element
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		// add and remove elements
		void push_back(const std::string &);
		void push_back(std::string &&);
		void pop_back();
		// element access
		std::string& front();
		std::string& back();
		std::string& front() const;
		std::string& back() const;
		std::string& operator[](std::size_t n) { return data->at(n); }
		const std::string& operator[](std::size_t n) const
			{ return data->at(n); }
	private:
		std::shared_ptr<std::vector<std::string>> data;
		// throws msg if data[i] isn't valid
		void check(size_type i, const std::string &msg) const;
};

// constructors
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) :
	data(std::make_shared<std::vector<std::string>>(il)) {}

// copy assignment operator
StrBlob&
StrBlob::operator=(const StrBlob &rhs)
{
	auto temp = std::make_shared<std::vector<std::string>>(*rhs.data);
	data = temp;
	return *this;
}

// members
void StrBlob::check(size_t i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

void StrBlob::pop_back()
{
	check(0, "back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void
StrBlob::push_back(const std::string &t)
{
	data->push_back(t);
	std::cout << "bush_back(const std::string &) &\n";
}

void
StrBlob::push_back(std::string &&t)
{
	data->push_back(std::move(t));
	std::cout << "bush_back(const std::string &) &&\n";
}

// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend StrBlobPtr operator-(const StrBlobPtr &, const StrBlobPtr &);
	friend StrBlobPtr operator+(const StrBlobPtr &, const size_t);
	friend StrBlobPtr operator-(const StrBlobPtr &, const size_t);
	public:
		StrBlobPtr() : curr(0) {}
		StrBlobPtr(const StrBlob &a, size_t sz = 0) :
			wptr(a.data), curr(sz) {}
		std::string& deref() const;
		std::string& operator[](std::size_t);
		const std::string& operator[](std::size_t) const;
		StrBlobPtr& operator-=(const StrBlobPtr &);
		StrBlobPtr& operator+=(const size_t);
		StrBlobPtr& operator-=(const size_t);
		StrBlobPtr operator++();
		StrBlobPtr operator++(int);
		StrBlobPtr operator--();
		StrBlobPtr operator--(int);
	private:
		// check returns a shared_ptr to the vector if the check succeeds
		std::shared_ptr<std::vector<std::string>>
			check(std::size_t, const std::string &) const;
		// store a weak_ptr, which means the underlying vector might be destroyed
		std::weak_ptr<std::vector<std::string>> wptr;
		size_t curr;            // current position within the array
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();     // is the vector still around
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;     // otherwise, return a shared_ptr to the vector
}

std::string&
StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p) is the vector to which this object points

}

// prefix: return a reference to the incremented object
StrBlobPtr
StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

// postfix: increment/decrement the object but return the unchanged value
StrBlobPtr
StrBlobPtr::operator++(int)
{
	auto ret = *this;
	++*this;  // call class' prefix increment
	return ret;
}

// prefix: return a reference to the decremented object
StrBlobPtr
StrBlobPtr::operator--()
{
	check(curr, "increment past end of StrBlobPtr");
	--curr;
	return *this;
}

// postfix: decrement the object but return the unchanged value
StrBlobPtr
StrBlobPtr::operator--(int)
{
	auto ret = *this;
	--*this;  // call class' prefix increment
	return ret;
}

// subscript: return reference at n
std::string&
StrBlobPtr::operator[](std::size_t n)
{
	auto p = check(n, "subscript out of bound");
	return (*p)[n];
}

const std::string&
StrBlobPtr::operator[](std::size_t n) const
{
	auto p = check(n, "subscript out of bound");
	return (*p)[n];
}

StrBlobPtr&
StrBlobPtr::operator-=(const StrBlobPtr &rhs)
{
	curr -= rhs.curr;
	return *this;
}

StrBlobPtr&
StrBlobPtr::operator+=(const size_t n)
{
	curr += n;
	return *this;
}

StrBlobPtr&
StrBlobPtr::operator-=(const size_t n)
{
	curr -= n;
	return *this;
}

// these members can't be defined until StrStrBlob and StrBlobPtr are defined.
StrBlobPtr StrBlob::begin() const { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() const { return StrBlobPtr(*this, data->size()); }

// non-member function
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);    // delegates to == class operator
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data < *rhs.data;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.deref() == rhs.deref();
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.deref() < rhs.deref();
}

StrBlobPtr operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto total = lhs;
	total -= rhs;
	return total;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, const size_t n)
{
	auto sum = lhs;
	sum += n;
	return sum;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, const size_t n)
{
	auto total = lhs;
	total -= n;
	return total;
}
#endif
