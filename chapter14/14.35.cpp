/*
 * Exercise 14.35: Write a class like PrintString that reads a line of input
 * from an istream and returns a string representing what was read. If the read
 * fails, return the empty string.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class ReadLine {
	public:
		ReadLine(std::istream &in = std::cin) : is(in) {}
		std::string& operator()(std::string &);
	private:
		std::istream &is;
};

std::string&
ReadLine::operator()(std::string &s)
{
	std::getline(is, s);
	if (!is)
		s.clear();
	return s;
}

class PrintString {
	public:
		PrintString(std::ostream &o = std::cout, char c = ' ')
			: os(o), step(c) {}
		void operator()(const std::string &s) const { os << s << step; }
	private:
		std::ostream &os;
		char step;
};

int main()
{
	ReadLine read;
	PrintString print(std::cout, '\n');
	std::string line;
	print("Enter a line of text:");
	read(line);
	print(line);
	return 0;
}
