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
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i + 1) { }
		std::string get_str() const { return *ps; }
		int get_copy_count() const { return i; }
	private:
		std::string *ps;
		int i;
};

int main()
{
	HasPtr str1("copy me");
	HasPtr str2 = str1;
	HasPtr str3 = str2;

	std::cout << str1.get_str() << ' ' << str1.get_copy_count() << '\n'
		      << str2.get_str() << ' ' << str2.get_copy_count() << '\n'
		      << str3.get_str() << ' ' << str3.get_copy_count() << '\n';
	return 0;
}
