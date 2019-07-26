/*
 * Exercise 18.7: Define your Blob and BlobPtr classes from Chapter 16 to use
 * function try blocks for their constructors.
 *
 * By Faisal Saadatmand

 */

#ifndef BLOB_H
#define BLOB_H

#include <exception>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

// forward declarations
template <typename> class BlobPtr;
template <typename> class Blob; // needed for parameters in operator==
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
	friend bool operator!=<T>(const Blob<T> &, const Blob<T> &);
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;
		Blob() try : data(std::make_shared<std::vector<T>>()) {}
		catch(const std::bad_alloc &e) {std::cerr << e.what() << std::endl; };
		Blob(std::initializer_list<T> il) try :
			data(std::make_shared<std::vector<T>>(il)) {}
		catch(const std::bad_alloc &e) {std::cerr << e.what() << std::endl; };
		template <typename It> Blob(It b, It e);
		size_type size() const { return data->size(); }
		bool empty() const { return data->size(); }
		void push_back(const T &t) { data->push_back(t); }
		void push_back(const T &&t) { data->push_back(std::move(t)); }
		void pop_back();
		BlobPtr<T> begin() const;
		BlobPtr<T> end() const;
		T& front();
		T& back();
		T& front() const;
		T& back() const;
		T& operator[](size_type n) { return (*data)[n]; }
	private:
		std::shared_ptr<std::vector<T>> data;
		void check(size_type, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
template <typename It>
inline Blob<T>::Blob(It b, It e) :
	data(std::make_shared<std::vector<T>>(b , e)) {}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop on empty container");
	data->pop_back();
}

template <typename T>
T& Blob<T>::front()
{
	check(0, "front on empty container");
	return data->front();
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty container");
	return data->back();
}

template <typename T>
T& Blob<T>::front() const
{
	check(0, "front on empty container");
	return data->front();
}

template <typename T>
T& Blob<T>::back() const
{
	check(0, "back on empty container");
	return data->back();
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return lhs->data == rhs->data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return !(lhs == rhs);
}

template <typename T>
class BlobPtr {
	public:
		// function try block is not necessary because weak_ptr constructors
		// guarantee not to throw exceptions
		BlobPtr() : curr(0) {}
		BlobPtr(const BlobPtr<T> &a, std::size_t sz = 0) :
			wptr(a.data), curr(sz) {}
		T& operator*() const;
		BlobPtr& operator++();
		BlobPtr& operator--();
	private:
		std::shared_ptr<std::vector<T>>
			check(std::size_t, const std::string &) const;
		std::weak_ptr<std::vector<T>> wptr;
		std::size_t curr;
};

template <typename T>
T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of container");
	++curr;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "decrement past end of container");
	--curr;
}

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();     // is the vector still around
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;     // otherwise, return a shared_ptr to the vector
}

// these members can't be defined until StrStrBlob and StrBlobPtr are defined.
template <typename T>
BlobPtr<T> Blob<T>::begin() const { return BlobPtr<T>(*this); }

template <typename T>
BlobPtr<T> Blob<T>::end() const { return BlobPtr<T>(*this, data->size()); }

#endif
