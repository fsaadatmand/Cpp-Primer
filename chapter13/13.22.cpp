/*
 * Exercise 13.22: Assume that we want HasPtr to behave like a value. That is,
 * each object should have its own copy of the string to which the objects
 * point. We’ll show the definitions of the copy-control members in the next
 * section. However, you already know everything you need to know to implement
 * these members. Write the HasPtr copy constructor and copy-assignment
 * operator before reading on.
 *
 * By Faisal Saadatmand
 */


#include <iostream>
#include <string>

class HasPtr {
	friend std::ostream& print(std::ostream &, const HasPtr &);
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		~HasPtr() { delete ps; }
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i) {}
		HasPtr& operator=(const HasPtr&);
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
	return *this;
}
 
std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << p.i;
	return os;
}

int main()
{
	HasPtr str1("copy me"), str2;
	str2 = str1;
	HasPtr str3(str1);
	print(std::cout, str1) << '\n';
	print(std::cout, str2) << '\n';
	print(std::cout, str3) << '\n';
	return 0;
}
