/*
 * Exercise 7.40: Choose one of the following abstractions (or an abstraction
 * of your own choosing). Determine what data are needed in the class. Provide
 * an appropriate set of constructors. Explain your decisions.
 * 
 * Answer: in the interest of brevity, our class has only 4 data members. The
 * set of constructors to initialize an object of the class is made up of the
 * default constructor, a constructor for an employee number, a constructor that
 * initializes the rest of the members, and finally an istream constructor. For
 * general initialization uses, this set should suffice. However, depending on
 * how we intend to create and initialize objects of this class in special case,
 * we would may need to add constructors or refine the existing ones.
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
		Employee_data() = default;
		Employee_data(const std::string &num) : employeeNo(num) {}
		Employee_data(const std::string &fn, const std::string &ln,
				      const std::string &num, unsigned sal) :
			          firstName(fn), lastName(ln),
					  employeeNo(num), salary(sal) {} 
		Employee_data(std::istream &is) { read(is, *this); }
	private:
		std::string firstName;
		std::string lastName;
		std::string employeeNo;
		unsigned salary = 0;
};

#endif
