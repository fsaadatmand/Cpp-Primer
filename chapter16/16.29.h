/*
 * Exercise 16.29: Revise your Blob class to use your version of shared_ptr
 * rather than the library version.
 *
 * By Faisal Saadatmand
 */

#ifndef BLOB_H
#define BLOB_H

#include <exception>
#include <initializer_list>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "16.28/shared_ptr.h"
#include "16.28/DebugDeleter.h"

// forward declarations
template <typename> class Blob; // needed for parameters in operator==
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
	friend bool operator==<T>(const Blob<T> &, const Blob<T> &);
	friend bool operator!=<T>(const Blob<T> &, const Blob<T> &);
	public:
		typedef T value_type;
		typedef typename std::vector<T>::size_type size_type;
		Blob() : data(new std::vector<T>(), DebugDeleter()) {}
		Blob(std::initializer_list<T> il) :
			data(new std::vector<T>(il), DebugDeleter()) {}
		template <typename It> Blob(It b, It e);
		size_type size() const { return data->size(); }
		bool empty() const { return data->size(); }
		void push_back(const T &t) { data->push_back(t); }
		void push_back(const T &&t) { data->push_back(std::move(t)); }
		void pop_back();
		typename std::vector<T>::iterator begin() const { return data->begin(); }
		typename std::vector<T>::iterator end() const { return data->end(); }
		T& front();
		T& back();
		T& front() const;
		T& back() const;
		T& operator[](size_type n) { return (*data)[n]; }
	private:
		shared_ptr<std::vector<T>> data;
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
	data(new std::vector<T>(b , e), DebugDeleter()) {}

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

#endif /* BLOB_H */
