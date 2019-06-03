/*
 * Exercise 13.31: Give your class a < operator and define a vector of HasPtrs.
 * Give that vector some elements and then sort the vector. Note when swap is
 * called.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasPtr {
	friend std::ostream& print(std::ostream &, const HasPtr &);
	friend void swap(HasPtr &, HasPtr &);
	public:
		HasPtr(const std::string &s = std::string()) :
			ps(new std::string(s)), i(0) {}
		~HasPtr() { delete ps; }
		HasPtr(const HasPtr& rhs) :
			ps(new std::string(*rhs.ps)), i(rhs.i) {}
		HasPtr& operator=(HasPtr);
		bool operator<(const HasPtr &rhs) { return *ps < *rhs.ps; }
	private:
		std::string *ps;
		int i;
};

HasPtr&
HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap(HasPtr &lhs, HasPtr &rhs)\n";
}

std::ostream& print(std::ostream &os, const HasPtr &p)
{
	os << p.ps << ' ' << *p.ps << ' ' << p.i;
	return os;
}

int main()
{
	std::vector<HasPtr> hpvec{{"shoe"}, {"girl"}, {"zoo"}, {"black"}, {"door"}};
	sort(hpvec.begin(), hpvec.end());
	for (const auto &elem : hpvec)
		print(std::cout, elem) << '\n';
	return 0;
}
