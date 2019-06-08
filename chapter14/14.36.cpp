/*
 * Exercise 14.36: Use the class from the previous exercise to read the
 * standard input, storing each line as an element in a vector.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>

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

// Note: read will stop if it hit an error or an empty line
int main()
{
	ReadLine read;
	PrintString print(std::cout, '\n');
	std::string line;
	std::vector<std::string> text;
	while (!read(line).empty())
		text.push_back(line);
	for (const auto &line : text)
		print(line);
	return 0;
}
