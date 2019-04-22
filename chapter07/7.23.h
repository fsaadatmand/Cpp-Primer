/*
 * Exercise 7.23: Write your own version of the Screen class.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Screen {
	public:
		using pos = std::string::size_type;
	private:
		pos cursor{0};
		pos height{0}, width{0};
		std::string contents;
};
