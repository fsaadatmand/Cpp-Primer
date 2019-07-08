/*
 * Exercise 16.28: Write your own versions of shared_ptr and unique_ptr.
 *
 * By Faisal Saadatmand
 */

/*
 * NOTE: This implementation is modelled on cppreference.org specifications,
 * with one exception: when swapping two unique_ptr, the deleter is not swapped.
 * This seems to simplify, the reset operation. Since the type of the deleter
 * is part of the pointer's type, any operations that takes a binary parameter,
 * such as move, swap, or reset, must have the types of its parameter match.
 * Therefore, it is unnecessary to copy the deleter because the destination's
 * deleter will always match the source's. This seems acceptable for the time
 * being.
 * Refer to https://en.cppreference.com/w/cpp/memory/unique_ptr
 * To simplify the code, the implementation uses a small set of key operations,
 * such as get, swap, operator boo() to perform the other operations. The
 * deleter is stored directly as class data member.
 */

#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <functional>
#include <memory>
#include <ostream>

template <typename T, typename D = std::default_delete<T>>
class unique_ptr {
	public:
		unique_ptr() = default;
		unique_ptr(std::nullptr_t, D d = std::default_delete<T>()) noexcept : del(d) {}
		explicit unique_ptr(T* ptr) : p(ptr) {}
		explicit unique_ptr(T* ptr, D d) : p(ptr), del(d) {}
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr(unique_ptr&& ptr) noexcept;
		unique_ptr& operator=(const unique_ptr&) = delete;
		unique_ptr& operator=(unique_ptr&&) noexcept;
		~unique_ptr() { del(p); }
		T* get() const noexcept { return p; }
		void swap(unique_ptr&) noexcept;
		T* release();
		void reset(T* q = nullptr) noexcept;
		operator bool() const noexcept { return this->get() != nullptr; }
		T& operator*() const { return *p; };
		T* operator->() const noexcept { return & this->operator*(); };
	public:
		T* p = nullptr;
		D del;
};

template <typename T, typename D>
unique_ptr<T, D>::unique_ptr(unique_ptr&& ptr) noexcept : p(ptr.p), del(ptr.del)
{
	ptr.p = nullptr;
}

template <typename T, typename D>
unique_ptr<T, D>&
unique_ptr<T, D>::operator=(unique_ptr&& rhs) noexcept
{
	if (this != &rhs)
		unique_ptr<T, D>(std::move(rhs)).swap(*this);
	return *this;
}

template <typename T, typename D>
void unique_ptr<T, D>::swap(unique_ptr& ptr) noexcept
{
	using std::swap;
	swap(p, ptr.p);
//	the deleter is not swapped
}

template <typename T, typename D>
T* unique_ptr<T, D>::release()
{
	auto ret = this->get();
	this->p = nullptr;
	return ret;
}

template <typename T, typename D>
void unique_ptr<T, D>::reset(T* q) noexcept
{
	unique_ptr<T, D>(q).swap(*this); // note: del is not swapped
}

template <typename T, typename D>
bool operator==(const unique_ptr<T, D>& lhs, const unique_ptr<T, D>& rhs)
{
	return lhs.get() == rhs.get();
}

template <typename T, typename D>
bool operator==(const unique_ptr<T, D>& ptr, std::nullptr_t)
{
	return !ptr;
}

template <typename T, typename D>
bool operator!=(const unique_ptr<T, D>& lhs, const unique_ptr<T, D>& rhs)
{
	return !(lhs == rhs);
}

template <typename T, typename D>
bool operator!=(const unique_ptr<T, D>& ptr, std::nullptr_t)
{
	return ptr;
}

template <typename T, typename D>
bool operator<(const unique_ptr<T, D>& lhs, const unique_ptr<T, D>& rhs)
{
	return std::less<T*>()(lhs.get(), rhs.get());
}

template <typename T, typename D>
std::ostream& operator<<(std::ostream& os, const unique_ptr<T, D>& ptr)
{
	return os << ptr.get();
}

#endif // UNIQUE_PTR_H
