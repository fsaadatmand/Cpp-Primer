/*
 * Exercise 14.32: Define a class that holds a pointer to a StrBlobPtr. Define
 * the overloaded arrow operator for that class.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include "14.30a.h"  // StrBlob and StrBlobPtr

class StrBlobPtrPtr {
	public:
		StrBlobPtrPtr() = default;
		StrBlobPtrPtr(StrBlobPtr *p) : pp(p) { }
		std::string& operator*() const { return **pp; }
		std::string* operator->() const { return & this->operator*(); }
	private:
		StrBlobPtr *pp = nullptr;
};

int main()
{
	StrBlob s{"one", "two", "three", "four"};
	StrBlobPtr sp(s);
	std::cout << sp->back() << '\n';
	StrBlobPtrPtr spp(&sp);
	std::cout << spp->back() << '\n';
	spp = nullptr;   // don't leave behind dangling pointer
	return 0;
}
