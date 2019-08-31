/*
 * Exercise 13.58: Write versions of class Foo with print statements in their
 * sorted functions to test your answers to the previous two exercises.
 *
 * By Faisal Saadatmand
 *
 * Note: uncomment the version of sorted() const & to test the code.
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Foo {
	public:
		Foo() = default;
		Foo(const std::vector<int> &v) : data(v) { }
		Foo(const Foo &rhs) : data(rhs.data) { }
		Foo& operator=(const Foo &) &;
		Foo sorted() &&;
		Foo sorted() const &;
		std::vector<int>::const_iterator begin() const { return data.begin(); }
		std::vector<int>::const_iterator end() const { return data.end(); }
	public:
		std::vector<int> data;
};

Foo&
Foo::operator=(const Foo &rhs) &
{
	auto newdata = rhs.data;
	data = newdata;
	return *this;
}


//Foo
//Foo::sorted() const & {
//	std::cout << "sorted() const &\n";
//	Foo ret(*this);  // ret is lvalue
//	return ret.sorted();
//}


Foo Foo::sorted() const &
{
	std::cout << "sorted() const &\n";
	return Foo(*this).sorted(); // ret is rvalue
}

Foo
Foo::sorted() &&
{
	std::cout << "sorted() &&\n";
	sort(data.begin(), data.end());
	return *this;
}


Foo retVal()
{
	Foo ret({453, 345, 3, 123, 56, 73});
	return ret;
}

Foo &retFoo()
{
	static Foo ret({453, 345, 3, 123, 56, 73});
	return ret;
}

std::ostream& print(std::ostream &os, const Foo &someFoo)
{
	for (const auto &elem : someFoo)
		os << elem << ' ';
	return os;
}

int main()
{
	print(std::cout, retVal().sorted()) << '\n';
	print(std::cout, retFoo().sorted()) << '\n';
	return 0;
}
