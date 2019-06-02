/*
 * Exercise 13.19: Does your Employee class need to define its own versions of
 * the copy-control members? If so, why? If not, why not? Implement whatever
 * copy-control members you think Employee needs.
 *
 * By Faisal Saadatmand
 *
 * The synthesized copy constructor would suffice, because we only need to
 * generate a new id number when we construct an object, not when we copy
 * construct, i.e. only when we add an employee information to the database. In
 * addition to copy initializing an object from another, this allows us to pass
 * and return object by value to and from functions while preserving the
 * employee's id and the static member number.
 *
 * It is trickier with the copy assignment operator. The synthesized version
 * copies the name and id but does not increment the static member number.
 * However, the number is incremented by the constructor when the object is
 * created before the assignment. If this the desired behaviour then the
 * synthesized version is adequate (we definitely do not want to define a copy
 * assign operator that decrements the static member number). That said, a
 * better design would be to disallow the copy assignment operator altogether,
 * for it would not make sense to assign one employ info to another.
 *
 * The class does not need a defined destructor, because decrementing the
 * static member number when we destroy an object could potentially generate an
 * old employee id to a newly constructed added one.
 */

#include <iostream>
#include <string>

class Employee {
	friend std::ostream& print(std::ostream &, const Employee &);
	public:
		Employee() : id(++number) {}  // default constructor
		Employee(std::string s) : name(s), id(++number) {}
		Employee& operator=(const Employee &) = delete;
	private:
		std::string name;
		unsigned id = 0;
		static unsigned number;
};

unsigned Employee::number = 0;

std::ostream& print(std::ostream &os, const Employee &e)
{
	os << e.name << ' ' << e.id << ' ' << Employee::number;
	return os;
}

void f(const Employee e)
{
	print(std::cout, e) << '\n';	
}

int main()
{
	Employee a("Ken, Thompson");
	print(std::cout, a) << '\n'; 
	Employee b("Torvalds, Linus");
	print(std::cout, b) << '\n';  
	f(a);
	return 0;
}
