/* 
 * Exercise 14.49: Regardless of whether it is a good idea to do so, define a
 * conversion
 * By Faisal Saadatmand
 */

#ifndef Employee_data_H
#define Employee_data_H

#include <iostream>
#include <string>
#include <initializer_list>

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
		Employee& operator=(const std::string &);
		bool nodata() const;
		explicit operator bool() const { return !nodata(); }
	private:
		std::string firstName;
		std::string lastName;
		std::string employeeNo;
		double salary = 0.0;
};

// member functions
Employee&
Employee::operator=(const std::string &number)
{
	employeeNo = number;
	return *this;
}

bool
Employee::nodata() const
{
	return firstName.empty() && lastName.empty()
			&& employeeNo.empty() && !salary;
}

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
