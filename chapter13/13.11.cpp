/*
 * Exercise 13.11: Add a destructor to your HasPtr class from the previous
 * exercises.
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
	auto temp = new std::string(*rhs.ps);
	delete ps;
	ps = temp;
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
