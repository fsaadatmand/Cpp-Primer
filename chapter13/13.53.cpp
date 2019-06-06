/*
 * Exercise 13.53: As a matter of low-level efficiency, the HasPtr assignment
 * operator is not ideal. Explain why. Implement a copy-assignment and
 * move-assignment operator for HasPtr and compare the operations executed in
 * your new move-assignment operator versus the copy-and-swap version.
 *
 * By Faisal Saadatmand
 *
 * Answer: in terms of low-level efficiency, the copy-and-swap assignment
 * involves more functions, which could affect performance  due to the overhead
 * associated with calling a function.
 *
 * The following is comparison of the call stacks of the two implementations,
 * read top to bottom:
 *
 * copy-and-swap: copy
 * HasPtr(HasPtr &)
 * operator=(HasPtr)
 * swap(HasPtr &, HasPtr &)
 * ~HasPtr()
 * ~HasPtr()
 * ~HasPtr()
 * 
 * copy assignment operator:
 * HasPtr(HasPtr &)
 * operator=(const HasPtr &)
 * ~HasPtr()
 * ~HasPtr()
 *
 * copy-and-swap: move
 * HasPtr(HasPtr &&)
 * operator=(HasPtr)
 * swap(HasPtr &, HasPtr &)
 * ~HasPtr()
 * ~HasPtr()
 * ~HasPtr()
 *
 * move assignment operator:
 * operator=(HasPtr &&)
 * ~HasPtr()
 * ~HasPtr()
 */

#include <algorithm>
#include <iostream>
#include <string>

class HasPtr {
	friend std::ostream& print(std::ostream &, const HasPtr &);
	friend void swap(HasPtr &, HasPtr &);
	public:
		HasPtr(const std::string &s = std::string())
			: ps(new std::string(s)), i(0) {}
		HasPtr(const HasPtr& rhs)
			: ps(new std::string(*rhs.ps)), i(rhs.i)
				{std::cout << "HasPtr(HasPtr &)\n";}
		HasPtr(HasPtr &&p) noexcept
			: ps(p.ps), i(p.i) { p.ps = 0; std::cout << "HasPtr(HasPtr &&)\n"; }
		HasPtr& operator=(const HasPtr &);
		HasPtr& operator=(HasPtr &&) noexcept;
//		HasPtr& operator=(HasPtr rhs) { swap(*this,rhs); return *this; } 
		~HasPtr() { delete ps; std::cout << "~HasPtr()\n"; }
		bool operator<(const HasPtr &rhs) { return *ps < *rhs.ps; }
	private:
		std::string *ps;
		int i;
};

HasPtr&
HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	std::cout << "operator=(const HasPtr &)\n";
	return *this;
}

HasPtr&
HasPtr::operator=(HasPtr &&rhs) noexcept
{
	if (this != &rhs) {
		delete ps;
		ps = rhs.ps;
		i = rhs.i;
		rhs.ps = nullptr;
	}
	std::cout << "operator=(HasPtr &&)\n";
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap(HasPtr &, HasPtr &)\n";
}

std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << p.i;
	return os;
}

int main()
{
	HasPtr hp("hp string"), hp2("hp2 string");
	hp = hp2;
	std::cout << "done\n";
	return 0;
}
