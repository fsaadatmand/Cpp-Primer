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
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i + 1) {}
		HasPtr& operator=(const HasPtr&);
		std::string get_str() const { return *ps; }
		int get_copy_count() const { return i; }
	private:
		std::string *ps;
		int i;
};

HasPtr&
HasPtr::operator=(const HasPtr &rhs)
{
	ps = new std::string(*rhs.ps);
	i = rhs.i + 1;
	return *this;
}

int main()
{
	HasPtr str1("copy me"), str2, str3;
	str2 = str1;
	str3 = str2;
	std::cout << str1.get_str() << ' ' << str1.get_copy_count() << '\n'
		      << str2.get_str() << ' ' << str2.get_copy_count() << '\n'
		      << str3.get_str() << ' ' << str3.get_copy_count() << '\n';
	return 0;
}
