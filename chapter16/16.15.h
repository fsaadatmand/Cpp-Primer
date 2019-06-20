/*
 * Exercise 16.15: Implement input and output operators for your Screen
 * template. Which, if any, friends are necessary in class Screen to make the
 * input and output operators work? Explain why each friend declaration, if
 * any, was needed.
 *
 * By Faisal Saadatmand
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <exception>
#include <iostream>

// forward declarations
template <typename> class Screen; // needed for parameters in operators << and >>
template <typename T>
std::istream& operator>>(std::istream&, Screen<T>&);
template <typename T>
std::ostream& operator<<(std::ostream&, const Screen<T>&);

template <typename T>
class Screen {
	friend std::istream& operator>><T>(std::istream&, Screen<T>&);
	friend std::ostream& operator<<<T>(std::ostream&, const Screen<T>&);
	public:
		void set(const T& x, const T& y) { width = x, height = y; } 
	private:
		T width = 0;
		T height = 0;
};

template <typename T>
std::istream& operator>>(std::istream& is, Screen<T>& screen)
{
	T x, y;
	if(!(is >> x >> y))
		throw std::invalid_argument("invalid input");
	screen.width = x;
	screen.height = y;
	return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Screen<T>& screen)
{
	os << "width " << screen.width << '\n' << "height " << screen.height;
	return os;
}
#endif
