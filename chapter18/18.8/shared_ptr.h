/*
 * Exercise 16.28: Write your own versions of shared_ptr and unique_ptr.
 *
 * By Faisal Saadatmand
 */

/*
 * NOTE: This implementation is modelled on cppreference.org specifications.
 * Refer to https://en.cppreference.com/w/cpp/memory/shared_ptr
 * To simplify the code, the implementation uses a small set of key operations,
 * such as get, swap, operator boo() to perform the other operations. The
 * deleter is stored indirectly as a library function template type, which
 * handles the pointer to the function and its memory management automatically.
 */

#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <functional>
#include <memory>
#include <ostream>

template <typename T>
class shared_ptr {
	public:
		shared_ptr() = default; // uses in-class initialization
		shared_ptr(std::nullptr_t) noexcept {} // converting constructor
		explicit shared_ptr(T* ptr, std::function<void(T*)> f = nullptr)
					: p(ptr), del(f), use(new std::size_t(1)) {}
		shared_ptr(const shared_ptr& ptr) noexcept; // copy constructor
		shared_ptr(shared_ptr&&) noexcept; // move constructor
		~shared_ptr() noexcept; // destructor
		shared_ptr& operator=(const shared_ptr&) noexcept; // copy-assignment op
		shared_ptr& operator=(shared_ptr&&) noexcept; // move-assignment op
		T* get() const noexcept { return p; }
		operator bool() const noexcept { return this->get() != nullptr; }
		void swap(shared_ptr&) noexcept;
		bool unique() const noexcept { return this->use_count() == 1; }
		std::size_t use_count() const noexcept { return (!*this) ? 0 : *use; }
		void reset() noexcept;
		void reset(T*, std::function<void(T*)> d = nullptr);
		T& operator*() const noexcept { return *this->get(); }
		T* operator->() const noexcept { return & this->operator*(); }
	private:
		T *p = nullptr; // built-in pointer
		std::function<void(T*)> del = nullptr; // callable deleter
		std::size_t *use = nullptr; // reference counter
		void decr_n_free();
};

template <typename T>
inline shared_ptr<T>::shared_ptr(const shared_ptr& ptr) noexcept :
				p(ptr.p), del(ptr.del), use(ptr.use)
{
	if (*this)
		++*use;
}

template <typename T>
inline shared_ptr<T>::shared_ptr(shared_ptr&& ptr) noexcept :
				p(ptr.p), del(ptr.del), use(ptr.use)
{
	ptr.p = nullptr;
	ptr.del = nullptr;
	ptr.use = nullptr;
}

template <typename T>
inline shared_ptr<T>&
shared_ptr<T>::operator=(const shared_ptr &rhs) noexcept
{
	if (this != &rhs) {
		if (*this)
			decr_n_free();
		shared_ptr<T>(rhs).swap(*this);
	}
	return *this;
}

template <typename T>
inline shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& rhs) noexcept
{
	if (this != &rhs) {
		if (*this)
			decr_n_free();
		shared_ptr<T>(std::move(rhs)).swap(*this);
	}
	return *this;
}

template <typename T>
inline shared_ptr<T>::~shared_ptr<T>() noexcept
{
	if (*this)
		decr_n_free();
}

template <typename T>
inline void shared_ptr<T>::swap(shared_ptr<T>& r) noexcept
{
	using std::swap;
	swap(p, r.p);
	swap(use, r.use);
	swap(del, r.del);
}

template <typename T>
inline void shared_ptr<T>::reset() noexcept
{
	shared_ptr<T>().swap(*this); 
}

template <typename T>
inline void shared_ptr<T>::reset(T* q, std::function<void(T*)> d)
{
	shared_ptr<T>(q, d).swap(*this); 
}

template <typename T>
inline void shared_ptr<T>::decr_n_free()
{
	if (--*use == 0) {
		(del) ? del(p) : delete p;
		delete use;
	} 
	p = nullptr;
	use = nullptr;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, shared_ptr<T> ptr)
{
	return os << ptr.get();
}

template <typename T>
bool operator==(const shared_ptr<T>& lhs, const shared_ptr<T>& rhs)
{
	return lhs.get() == rhs.get();
}

template <typename T>
bool operator==(const shared_ptr<T>& ptr, std::nullptr_t)
{
	return !ptr;
}

template <typename T>
bool operator!=(const shared_ptr<T>& lhs, const shared_ptr<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator!=(const shared_ptr<T>& ptr, std::nullptr_t)
{
	return ptr;
}

template <typename T>
bool operator<(const shared_ptr<T>& lhs, const shared_ptr<T>& rhs)
{
	return std::less<T*>()(lhs.get(), rhs.get());
}

#endif // SHARED_PTR_H
