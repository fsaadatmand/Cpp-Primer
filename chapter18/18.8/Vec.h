/*
 * Exercise 16.58: Write the emplace_back function for your StrVec class and
 * for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).
 * By Faisal Saadatmand
 */

#ifndef VEC_H
#define VEC_H

#include <memory>
#include <string>
#include <vector>
#include <utility>

template <typename T>
class Vec {
	public:
		Vec() noexcept = default;
		Vec(const Vec<T>&);
		Vec<T>& operator=(const Vec<T>&);
		~Vec<T>() noexcept { free(); };
		void push_back(const T&);
		template <typename... Args> void emplace_back(Args&&... args);
		std::size_t size() const { return first_free - elements; }
		std::size_t capacity() const { return cap - elements; }
		T* begin() const { return elements; }
		T* end() const { return first_free; }
		void reserve(const std::size_t&);
		void resize(const std::size_t&, const T& arg = T());
	private:
		static std::allocator<T> alloc;
		void chk_n_alloc() {if (size() == capacity()) reallocate(); };
		std::pair<T*, T*> alloc_n_copy(const T*, const T*);
		void free();
		void reallocate(std::size_t n = 0);
		T* elements = nullptr;
		T* first_free = nullptr;
		T* cap = nullptr;
};

// static members
template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(const Vec<T>& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T> &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>
void Vec<T>::push_back(const T &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template <typename T> 
template <typename... Args>
inline void Vec<T>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}


template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
void Vec<T>::reallocate(std::size_t n) // n is optional
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

template <typename T>
void Vec<T>::reserve(const std::size_t& n)
{
	if (n > capacity()) // requested size is bigger than capacity
		reallocate(n);  // use optional argument
}

template <typename T>
void Vec<T>::resize(const size_t& n, const T& arg)
{
	if (n > capacity())
		reallocate(n);
	auto newsize = first_free + (n - size());	// points to the new first_free
	while (first_free != newsize)
		if (first_free < newsize)
			alloc.construct(first_free++, arg);
		else
			alloc.destroy(--first_free);
}
#endif // VEC_H
