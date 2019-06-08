/*
 * Exercise 14.26: Define subscript operators for your StrVec, String, StrBlob,
 * and StrBlobPtr classes.
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
	public:
		StrBlobPtr() : curr(0) {}
		StrBlobPtr(const StrBlob &a, size_t sz = 0) :
			wptr(a.data), curr(sz) {}
		std::string& deref() const;
		StrBlobPtr& incr();    // prefix version
		std::string& operator[](std::size_t);
		const std::string& operator[](std::size_t) const;
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

// prefix: return a reference to the increment object
StrBlobPtr&
StrBlobPtr::incr()
{
	//if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
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
#endif
