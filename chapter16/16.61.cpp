/*
 * Exercise 16.61: Define your own version of make_shared.
 *
 * By Faisal Saadatmand
 */

// shared_ptr code is from exercise 16.28. Scroll all the way down to
// make_shared function for its definition.

#include <functional>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

template <typename T>
class shared_ptr {
	public:
		shared_ptr() = default; // uses in-class initialization
		shared_ptr(std::nullptr_t) noexcept {} // converting constructor
		explicit shared_ptr(T* ptr, std::function<void(T*)> f = nullptr)
					: p(ptr), del(f), use(new std::size_t(1)) {}
		shared_ptr(const shared_ptr& ptr) noexcept; // copy constructor
		shared_ptr(shared_ptr&&) noexcept; // move constructor
		~shared_ptr(); // destructor
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
inline shared_ptr<T>::~shared_ptr<T>()
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

// make_shared function definition
template <typename T, typename... Args>
shared_ptr<T> make_shared(Args&&... args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
	// shared_ptr to an int of value 42
	auto pInt = make_shared<int>(42);
	std::cout << *pInt << '\n';

	// shared_ptr to a string of 10 c charters 
	auto pStr = make_shared<std::string>(10, 'c');
	std::cout << *pStr << '\n';

	// shared_ptr to a vector of int of size 10
	auto pVec = make_shared<std::vector<int>>(10);
	std::cout << pVec->empty() << '\n';
	/// add an element to the vector
	pVec->push_back(42);
	std::cout << pVec->back() << '\n';

	return 0;
}
