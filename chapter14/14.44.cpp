/*
 * Exercise 14.44: Write your own version of a simple desk calculator that can
 * handle binary operations.
 *
 * By Faisal Saadatmand
 */

#include <exception>
#include <functional>
#include <iostream>
#include <limits>
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

int main()
{
	auto mod = [](const int i, const int j)
		{ return (!j) ? throw std::runtime_error("zero divisor") : i % j; };

	std::map<std::string, std::function<int(int, int)>> binops = {
		{"+", add},
		{"-", std::minus<int>()},
		{"/", divide()},
		{"*", [](const int i, const int j) { return i * j; }},
		{"%", mod}
	};

	using nlimits = std::numeric_limits<std::streamsize>;

	while (true) {
		try {
			std::string op;
			int lhs, rhs;
			if(!(std::cin >> lhs >> op >> rhs)) {
				if (std::cin.eof() || 'q')
					break;
				std::cin.clear(); // reset stream to a valid state
				std::cin.ignore(nlimits::max(), '\n'); // flush stream
				throw std::runtime_error("invalid expression");
			}
			auto key = binops.find(op);
			if (key != binops.cend())
				std::cout << key->second(lhs, rhs) << '\n';
			else
				throw std::runtime_error("invalid operator");
		} catch (std::runtime_error err) {
			std::cout << err.what() << '\n';
		}
	}
	return 0;
}
