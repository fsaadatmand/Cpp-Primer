/*
 * Exercise 14.8: Define an output operator for the class you chose in exercise
 * 7.40 from § 7.5.1 (p. 291).
 *
 * By Faisal Saadatmand 
 */

#ifndef Employee_data_H
#define Employee_data_H

#include <iostream>
#include <string>

class Employee {
	friend std::ostream& operator<<(std::ostream &, const Employee &);
	friend std::istream& read(std::istream &, Employee &);
	public:
		Employee() = default;
		Employee(const std::string &num) : employeeNo(num) {}
		Employee(const std::string &fn, const std::string &ln,
				      const std::string &num, unsigned sal) :
			          firstName(fn), lastName(ln),
					  employeeNo(num), salary(sal) {} 
		Employee(std::istream &is) { read(is, *this); }
	private:
		std::string firstName;
		std::string lastName;
		std::string employeeNo;
		double salary = 0.0;
};

// non-member functions
std::ostream& operator<<(std::ostream &os, const Employee &obj)
{
	os  << obj.firstName << " " << obj.lastName
		<< " " << obj.employeeNo << " " << obj.salary;
	return os;
}
#endif
