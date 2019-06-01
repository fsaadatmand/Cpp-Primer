/*
 * Exercise 13.27: Define your own reference-counted version of HasPtr.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class HasPtr {
	friend std::ostream& print(std::ostream &, const HasPtr &);
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
		~HasPtr();
		HasPtr(const HasPtr& rhs) :
			ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
		HasPtr& operator=(const HasPtr&);
	private:
		std::string *ps;
		int i;
		std::size_t *use;
};

HasPtr::~HasPtr()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}

HasPtr&
HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << *p.use;
	return os;
}

void func(const HasPtr &p)
{
	HasPtr temp;
	temp = p;
	std::cout << "p: ";
	print(std::cout, p) << '\n';;
	std::cout << "temp: ";
	print(std::cout, temp) << '\n';;
}

int main()
{
	std::cout << "HasPtr str1(\"copy me\"), str2;\n"; 
	HasPtr str1("copy me"), str2;
	std::cout << "str1: ";
	print(std::cout, str1) << '\n';
	std::cout << "str2: ";
	print(std::cout, str2) << '\n';

	std::cout << "\nstr2 = str1;\n";
	str2 = str1;
	std::cout << "str1: ";
	print(std::cout, str1) << '\n';
	std::cout << "str2: ";
	print(std::cout, str2) << '\n';

	std::cout << "\nfunc(str1);\n";
	func(str1);

	std::cout << "\nstr1: ";
	print(std::cout, str1) << '\n';
	std::cout << "str2: ";
	print(std::cout, str2) << '\n';
	return 0;
}
