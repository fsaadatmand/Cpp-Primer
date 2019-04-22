/*
 * Exercise 7.24: Give your Screen class three constructors: a default
 * constructor; a constructor that takes values for height and width and
 * initializes the contents to hold the given number of blanks; and a
 * constructor that takes values for height, width, and a character to use as
 * the contents of the screen.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Screen {
	public:
		using pos = std::string::size_type;
		Screen() = default;
		Screen(pos ht, pos wd): height(ht), width(wd),
								contents(ht * wd, ' ') {}
		Screen(pos ht, pos wd, char c): height(ht), width(wd),
		                                contents(ht * wd, c) {}
	private:
		pos cursor{0};
		pos height{0}, width{0};
		std::string contents;
};
