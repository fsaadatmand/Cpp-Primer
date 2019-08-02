/*
 * Exercise 19.12: Define a pointer to member that can point to the cursor
 * member of class Screen. Fetch the value of Screen::cursor through that
 * pointer.
 *
 * By Faisal Saadatmand
 */

#include <iostream>

class Screen {
	public:
		using pos = std::string::size_type;
		char get_cursor() const { return contents[cursor]; }
		char get() const;
		char get(pos ht, pos wd) const;
		// return a pointer to cursor data memeber
		static const pos Screen::* cursor_data()
								{ return &Screen::cursor; }
	private:
		std::string contents;
		pos cursor = 10;
		pos height, width;
};

int main()
{
	Screen sobj;
	// point to cursor data member
	const Screen::pos Screen::*pcursor = Screen::cursor_data();
	// fetch value
	std::cout << sobj.*pcursor << '\n';
	return 0;
}
