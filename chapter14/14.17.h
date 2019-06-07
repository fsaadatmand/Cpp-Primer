/* 
 * Exercise 14.17: Should the class you chose for exercise 7.40 from § 7.5.1
 * (p. 291) define the equality operators? If so, implement them. If not,
 * explain why not.
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
	friend bool operator==(const Employee &, const Employee &);
	friend bool operator!=(const Employee &, const Employee &);
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

bool operator==(const Employee &lhs, const Employee &rhs)
{
	return lhs.firstName == rhs.firstName && lhs.lastName == rhs.lastName
		&& lhs.employeeNo == rhs.employeeNo && lhs.salary == rhs.salary;
}

bool operator!=(const Employee &lhs, const Employee &rhs)
{
	return !(lhs == rhs);
}
#endif
