/*
 * Exercise 13.19: Does your Employee class need to define its own versions of
 * the copy-control members? If so, why? If not, why not? Implement whatever
 * copy-control members you think Employee needs.
 *
 * By Faisal Saadatmand
 *
 * No, because we need to generate a new id number only when we construct an
 * object and when we copy an object either through direct or copy
 * initialization, we would like to preserve the employee's id. We also do not
 * need a defined destructor, because decrementing the static member number
 * when we destroy an object could potentially generate an old Employee id to a
 * newly constructed Employee object.
 */

#include <iostream>
#include <string>

class Employee {
	public:
		Employee() { id = ++number; }  // default constructor
		Employee(std::string s) : name(s), id(++number) {}
		std::string get_name() const { return name; }
		unsigned get_id() const { return id; }

	private:
		std::string name;
		unsigned id = 0;
		static unsigned number;
};

unsigned Employee::number = 0;

void print(Employee s)
{
	std::cout << s.get_name() << ' ' << s.get_id() << '\n';
}

int main()
{
	Employee a("Ken, Thompson"), b = a;
	Employee c("Torvalds, Linus");
	print(a); 
	print(b); 
	print(c); 
	return 0;
}
