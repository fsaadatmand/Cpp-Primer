/*
 * Exercise 9.51: Write a class that has three unsigned members representing
 * year, month, and day. Write a constructor that takes a string representing a
 * date. Your constructor should handle a variety of date formats, such as
 * January 1, 1900, 1/1/1900,
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

class Date {
	friend std::ostream& print(std::ostream &, const Date &);
	public:
		Date() = default;
		Date(const std::string &);         // constructor that takes string
		unsigned getMonth() const { return month; }
		unsigned getYear() const { return year; }
		unsigned getDay() const { return day; }
	private:
		unsigned year{0};
		unsigned month{0};
		unsigned day{0};
		static const std::string numbers;
		static const std::string characters;
		static const std::vector<std::string> months;
};

// static member definitions
const std::string Date::numbers{"0123456789"};
const std::string Date::characters{"adfjmnosADFJMNOS"};
const std::vector<std::string> Date::months{"January", "February", "March",
			"April", "May", "June", "July", "August", "September", "October",
			"November", "December"};

Date::Date(const std::string &s)
{
	std::string::size_type pos = 0;
	if ((pos = s.find_first_of(characters, pos)) != std::string::npos) {
		auto strtemp = s.substr(pos, pos + s.find_first_of('/', pos));
		for (decltype(months.size()) i = 0; i != months.size(); ++i)
			if (months[i].find(strtemp) != std::string::npos) {
				month = i + 1;      // + 1 because index starts at 0
				break;
			}
	} else if ((pos = s.find_first_of(numbers)) != std::string::npos)
		month = stoul(s.substr(pos));
	pos = s.find_first_of('/', pos);
	day = stoul(s.substr(pos = s.find_first_of(numbers, pos)));
	pos = s.find_first_of('/', pos);
	year = stoul(s.substr(pos = s.find_first_of(numbers, pos)));
}

std::ostream& print(std::ostream &os, const Date &field)
{
	os << field.month << '/' << field.day <<  '/' 
	   << field.year;
	return os;
}

int main()
{
	 Date s1{"5/6/2019"};
	 Date s2{"Jan/8/1900"};
	 Date s3{"January/1/2011"};
	 Date s4{"July/22/1977"};
	 std::cout << s1.getMonth() << ' ' 
		 << s1.getDay() << ' '
		 << s1.getYear() << '\n';
	 print(std::cout, s1);
	 std::cout << '\n';
	 print(std::cout, s2);
	 std::cout << '\n';
	 print(std::cout, s3);
	 std::cout << '\n';
	 print(std::cout, s4);
	 std::cout << '\n';
	return 0;
}
