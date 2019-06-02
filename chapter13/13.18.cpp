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
	friend std::ostream& print(std::ostream &, const Employee &);
	public:
		Employee() { id = ++number; }  // default constructor
		Employee(std::string s) : name(s), id(++number) {}
		std::string get_name() const { return name; }
	private:
		std::string name;
		unsigned id = 0;
		static unsigned number;
};

unsigned Employee::number = 0;

std::ostream& print(std::ostream &os, const Employee &e)
{
	os << e.name << ' ' << e.id;
	return os;
}

int main()
{
	Employee a("Jobs, Steve"), b = a, c = b;
	print(std::cout, a) << '\n'; 
	print(std::cout, b) << '\n';  
	print(std::cout, c) << '\n'; 
	return 0;
}
