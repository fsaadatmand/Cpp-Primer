/*
 * Exercise 13.54: What would happen if we defined a HasPtr move-assignment
 * operator but did not change the copy-and-swap operator? Write code to test
 * your answer.
 *
 * By Faisal Saadatmand
 *
 * Answer: we would get a compile error because the call to the overloaded
 * assignment operator would be ambiguous-both move-assignment operator and
 * copy-and-swap operator have the same number and type of parameters.. 
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
		HasPtr& operator=(HasPtr &&) noexcept;
		HasPtr& operator=(HasPtr rhs) { swap(*this,rhs); return *this; } 
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
