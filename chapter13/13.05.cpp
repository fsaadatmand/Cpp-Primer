/*
 * Exercise 13.5: Given the following sketch of a class, write a copy
 * constructor that copies all the members. Your constructor should dynamically
 * allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps
 * points, rather than copying ps itself.
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
	private:
		std::string *ps;
		int i;
};

std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << p.i;
	return os;
}

int main()
{
	HasPtr str1("copy me");
	HasPtr str2 = str1;
	HasPtr str3 = str2;
	print(std::cout, str1) << '\n';
	print(std::cout, str2) << '\n';
	print(std::cout, str3) << '\n';
	return 0;
}
