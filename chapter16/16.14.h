/*
 * Exercise 16.14: Write a Screen class template that uses nontype parameters
 * to define the height and width of the Screen.
 *
 * By Faisal Saadatmand
 */

#ifndef SCREEN_H
#define SCREEN_H

template <typename T>
class Screen {
	public:
		void set(const T& x, const T& y) { width = x; height = y; } 
	private:
		T height = 0;
		T width = 0;
};
#endif
