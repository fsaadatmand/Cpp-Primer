/*
 * Exercise 7.32: Define your own versions of Screen and Window_mgr in which
 * clear is a member of Window_mgr and a friend of Screen.
 * 
 * Note: to gain access to private members in Screen, we have to declare clear
 * as a friend member function in Screen. This creates a circular
 * interdependencies among Screen, window_mgr and clear:
 *
 * Clear depends on Window_mgr, because it is declared as member function of
 * that class.  Window_mgr itself depends on Screen for its other members as
 * well.  Clear's definition depends on Screen to gain access to private
 * members of that class. Making clear a friend member function, means that
 * Screen now becomes dependent on Window_mgr, because--IMPORTANT--it is using
 * a member of Window_mgr: a class must be defined, and not just declared,
 * before its member could be accessed. (p. 278 - 279)  To solve this circular
 * interdependencies, the declaration of Screen must come first, followed by
 * the definition of Window_mgr. This allows us to create members of type
 * Screen, but we cannot access any elements of Screen before Screen is
 * defined. Thus, can only declare clear but not define it. Next we define
 * Screen and grant clear a friend status. Finally, we define clear.
 *
 * It is worth noting, that with this structure, the vector screens cannot be
 * initialized within the definition of Window_mgr for the same reason Screen
 * could not use clear. To overcome this, we would need to declare a member
 * function, initializeVector, and define it after Screen.
 * 
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
	public:
		using ScreenIndex = std::vector<Screen>::size_type;
		void clear(ScreenIndex);
	private:
		using pos = std::string::size_type;
		std::vector<Screen> createScreen(pos, pos, char);
		std::vector<Screen> screens{createScreen(24, 80, ' ')};
};

class Screen {
	public:
		using pos = std::string::size_type;

		friend void Window_mgr::clear(ScreenIndex);

		Screen() = default;
		Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		                                 contents(ht * wd, c) {}
		Screen(pos ht, pos wd) : height(ht), width(ht),
		                         contents(ht * wd, ' ') {}
		// members
		Screen &display(std::ostream &os)
		               { do_display(os); return *this; }
		const Screen &display(std::ostream &os) const
		               { do_display(os); return *this; }
		Screen &set(char);
		Screen &set(pos, pos, char);
		char get() const            // get the character at the cursor
		    { return contents[cursor]; }         // implicitly inline
		inline char get(pos ht, pos wd) const;   // explicitly inline
		Screen &move(pos r, pos c);   // can be made inline later

	private:
		void do_display(std::ostream &os) const {os << contents;}
		pos cursor{0};
		pos height{0};
		pos width{0};
		std::string contents;
};

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;     // set the new value at the current cursor location
	return *this;             // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;   // set specified location to given value
	return *this;
}

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;      // compute the row location
	cursor = row + c;         // move cursor to the column within that raw
	return *this;             // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
	pos row = r * width;       // compute row location
	return contents[row + c];  // return character at the given column
}

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string (s.height * s.height, ' ');
}

std::vector<Screen> Window_mgr::createScreen(pos ht, pos wd, char c)
{
	std::vector<Screen> sVec{Screen(ht, wd, c)};
	return sVec;
}
