/* 
 * Exercise 14.12: Define an input operator for the class you used in exercise
 * 7.40 from
 *
 * By Faisal Saadatmand
 */

#ifndef Employee_data_H
#define Employee_data_H

#include <iostream>
#include <string>

class Employee {
	friend std::ostream& operator<<(std::ostream &, const Employee &);
	friend std::istream& operator>>(std::istream &, Employee &);
	public:
		Employee() = default;
		Employee(const std::string &num) : employeeNo(num) {}
		Employee(const std::string &fn, const std::string &ln,
				      const std::string &num, unsigned sal) :
			          firstName(fn), lastName(ln),
					  employeeNo(num), salary(sal) {} 
		Employee(std::istream &is) { operator>>(is, *this); }
	private:
		std::string firstName;
		std::string lastName;
		std::string employeeNo;
		double salary = 0.0;
};

// non-member functions
std::istream& operator>>(std::istream &is, Employee &obj)
{
	is >> obj.firstName >> obj.lastName
	   >> obj.employeeNo >> obj.salary;
	if (!is)
		obj = Employee();
	return is;
}

std::ostream& operator<<(std::ostream &os, const Employee &obj)
{
	os  << obj.firstName << " " << obj.lastName
		<< " " << obj.employeeNo << " " << obj.salary;
	return os;
}
#endif
