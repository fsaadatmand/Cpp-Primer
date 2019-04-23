/*
 * Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p.
 * 291), decide whether any of the constructors might use delegation. If so,
 * write the delegating con- structor(s) for your class. If not, look at the
 * list of abstractions and choose one that you think would use a delegating
 * constructor. Write the class definition for that abstraction.
 *
 * By Faisal Saadatmand 
 *
 */

#ifndef Employee_data_H
#define Employee_data_H

#include <iostream>
#include <string>

class Employee_data {
	public:
		friend std::istream & read(std::istream &, Employee_data &);
		Employee_data(const std::string &fn, const std::string &ln,
				      const std::string &num, unsigned sal) :
			          firstName(fn), lastName(ln),
					  employeeNo(num), salary(sal) {} 
		Employee_data() : Employee_data("", "", "", 0) {}
		Employee_data(const std::string &num) : Employee_data("", "", num, 0) {}
		Employee_data(std::istream &is) : Employee_data() { read(is, *this); }
	private:
		std::string firstName;
		std::string lastName;
		std::string employeeNo;
		unsigned salary = 0;
};

#endif
