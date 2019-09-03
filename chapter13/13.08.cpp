/*
 * Exercise 13.8: Write the assignment operator for the HasPtr class from
 * exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
 * assignment operator should copy the object to which ps points.
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
	delete ps;
	ps = new std::string(*rhs.ps);
	i = rhs.i + 1;
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
