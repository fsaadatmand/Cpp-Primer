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
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) { }
		~HasPtr() { delete ps; }
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i) {}
		HasPtr& operator=(const HasPtr&);
		std::string *get_str() const { return ps; }
		int get_copy_count() const { return i; }
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
