/*
 * Exercise 19.17: Define a type alias for each distinct Screen member function
 * type.
 *
 * By Faisal Saadatmand
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
	public:
		enum Directions { HOME, FORWARD, BACK, UP, DOWN }; // need to be before Movement
		using pos = std::string::size_type;
		using Action = Screen& (Screen::*)(); // home(), forward(), back(), up(), down()
		using Movement = Screen& (Screen::*)(Directions); // move(Directions)
		using Cursor_Postion = char (Screen::*)() const; // get(), get_cursor()
		using Postion = char (Screen::*)(pos, pos) const; // get(pos, pos)
		char get_cursor() const { return contents[cursor]; }
		char get() const; 
		char get(pos ht, pos wd) const;
		Screen& move(Directions);
		Screen& home();
		Screen& forward();
		Screen& back();
		Screen& up();
		Screen& down();
	private:
		static Action Menu[];
		std::string contents;
		pos cursor;
		pos height, width;
};

// static member
Screen::Action Screen::Menu[] = { &Screen::home,
								  &Screen::forward,
								  &Screen::back,
								  &Screen::up,
								  &Screen::down,
								};

Screen& Screen::home()
{
	std::cout << "home()\n";
	return *this;
}

Screen& Screen::forward()
{
	std::cout << "forward()\n";
	return *this;
}

Screen& Screen::back()
{
	std::cout << "back()\n";
	return *this;
}

Screen& Screen::up()
{
	std::cout << "up()\n";
	return *this;
}

Screen& Screen::down()
{
	std::cout << "down()\n";
	return *this;
}

Screen& Screen::move(Directions cm)
{
	return (this->*Menu[cm]) ();
}
#endif // SCREEN_H
