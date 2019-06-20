/*
 * Exercise 14.30: Add dereference and arrow operators to your StrBlobPtr class
 * and to the ConstStrBlobPtr class that you defined in exercise 12.22 from §
 * 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return
 * const references because the data member in constStrBlobPtr points to a
 * const vector.
 */

#ifndef STRING_BLOG_H
#define STRING_BLOG_H

#include <fstream>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class ConstStrBlobPtr;

class StrBlob {
	friend class ConstStrBlobPtr;
	public:
		using size_type = std::vector<std::string>::size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		ConstStrBlobPtr begin() const;
		ConstStrBlobPtr end() const; 
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		// add and remove elements
		void push_back(const std::string &t) { data->push_back(t); }
		void pop_back();
		// element access
		std::string& front();
		std::string& back();
		std::string& front() const;
		std::string& back() const;
	private:
		std::shared_ptr<std::vector<std::string>> data;
		// throws msg if data[i] isn't valid
		void check(size_type, const std::string &) const;
};

// constructors
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) :
	data(std::make_shared<std::vector<std::string>>(il)) {}

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

// ConstStrBlobPtr throws an exception on attempts to access a nonexistent element
class ConstStrBlobPtr {
	public:
		ConstStrBlobPtr() : curr(0) {}
		ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :
			wptr(a.data), curr(sz) {}
		ConstStrBlobPtr& operator++();
		ConstStrBlobPtr operator++(int);
		const std::string& operator*() const;
		const std::string* operator->() const;
	private:
		// check returns a shared_ptr to the vector if the check succeeds
		std::shared_ptr<std::vector<std::string>>
			check(std::size_t, const std::string &) const;
		// store a weak_ptr, which means the underlying vector might be destroyed
		std::weak_ptr<std::vector<std::string>> wptr;
		size_t curr;            // current position within the array
};

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();     // is the vector still around
	if (!ret)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;     // otherwise, return a shared_ptr to the vector
}

const std::string&
ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

const std::string*
ConstStrBlobPtr::operator->() const
{
	return & this->operator*();
}

// prefix: return a reference to the increment object
ConstStrBlobPtr&
ConstStrBlobPtr::operator++()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

// postfix: increment object nut return a the unincrement object
ConstStrBlobPtr
ConstStrBlobPtr::operator++(int)
{
	auto ret = *this;
	check(curr, "increment past end of ConstStrBlobPtr");
	++*this;
	return ret;
}

// these members can't be defined until StrStrBlob and ConstStrBlobPtr are defined.
ConstStrBlobPtr StrBlob::begin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::end() const { return ConstStrBlobPtr(*this, data->size()); }
#endif
