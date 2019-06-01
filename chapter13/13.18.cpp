/*
 * Exercise 13.18: Define an Employee class that contains an employee name and
 * a unique employee identifier. Give the class a default constructor and a
 * constructor that takes a string representing the employee’s name. Each
 * constructor should generate a unique ID by incrementing a static data
 * member.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

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

void print_Employee(Employee s)
{
	std::cout << s.get_name() << ' ' << s.get_id() << '\n';
}

int main()
{
	Employee a("Jobs, Steve"), b = a, c = b;
	
	print_Employee(a); 
	print_Employee(b); 
	print_Employee(c); 

	return 0;
}
