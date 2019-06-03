/*
 * Exercise 13.30: Write and test a swap function for your valuelike version of
 * HasPtr. Give your swap a print statement that notes when it is executed.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class HasPtr {
	friend void swap(HasPtr &, HasPtr &);
	friend std::ostream& print(std::ostream &, const HasPtr &);
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		~HasPtr() { delete ps; }
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i) {}
		HasPtr& operator=(HasPtr);
	private:
		std::string *ps;
		int i;
};

HasPtr&
HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}
 
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap(HasPtr &lhs, HasPtr &rhs)\n";
}

std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << p.i;
	return os;
}

int main()
{
	HasPtr str1("lhs string");
	HasPtr str2("rhs string");

	std::cout << "str1: ";
	print(std::cout, str1) << '\n';
	std::cout << "str2: ";
	print(std::cout, str2) << '\n';
	
	swap(str1, str2);

	std::cout << "str1: ";
	print(std::cout, str1) << '\n';
	std::cout << "str2: ";
	print(std::cout, str2) << '\n';
	return 0;
}
