/*
 * Exercise 14.44: Write your own version of a simple desk calculator that can
 * handle binary operations.
 *
 * By Faisal Saadatmand
 */

#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>

int add(const int i, const int j)
{
	return i + j;
}

class divide {
	public:
		int operator()(const int denominator, const int divisor);
};

int
divide::operator()(const int denominator, const int divisor)
{
	if (!divisor)
		throw std::runtime_error("zero divisor");
	return denominator / divisor;
}

auto mod = [](const int i, const int j)
	{ return (!j) ? throw std::runtime_error("zero divisor") : i % j; };

int main()
{
	std::map<std::string, std::function<int(int, int)>> binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"/", divide()},
		{"*", [](const int i, const int j) { return i * j; }},
		{"%", mod}
	};

	while (true) {
		try {
			std::string op, input;
			int lhs, rhs;
			if (!std::getline(std::cin, input) || input == "q")
				break;
			std::istringstream line(input);
			if (!(line >> lhs >> op >> rhs))
				throw std::runtime_error("invalid expression");
			auto key = binops.find(op);
			if (key != binops.cend())
				std::cout << key->second(lhs, rhs) << '\n';
			else
				throw std::runtime_error("invalid operator");
		} catch (std::runtime_error err) {
			std::cerr << err.what() << '\n';
		}
	}
	return 0;
}
