/*
 * Exercise 13.11: Add a destructor to your HasPtr class from the previous
 * exercises.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class HasPtr {
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		~HasPtr() {std::cout << "destructing " << this << '\n';}
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
	std::cout << &str1 << '\n' << &str2 << '\n' << &str3 << '\n';
	return 0;
}
