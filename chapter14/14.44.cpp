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
#include <cmath>
#include <sstream>

double add(const double i, const double j)
{
	return i + j;
}

class divide {
	public:
		double operator()(const double denominator, const double divisor);
};

double
divide::operator()(const double denominator, const double divisor)
{
	if (!divisor)
		throw std::invalid_argument("zero divisor");
	return denominator / divisor;
}

auto mod = [](const int i, const int j)
	{ return (!j) ? throw std::invalid_argument("zero divisor") : i % j; };

int main()
{
	std::map<std::string, std::function<double(double, double)>> binops = {
		{"+", add},
		{"-", std::minus<double>()},
		{"/", divide()},
		{"*", [](const double i, const double j) { return i * j; }},
		{"%", mod},
		{"^", [](const double i, const double j) { return pow(i, j); }}
	};

	while (true) {
		std::string op, input;
		double lhs, rhs;
		if (!std::getline(std::cin, input) || input == "q")
			break;
		try {
			std::istringstream line(input);
			if (!(line >> lhs >> op >> rhs))
				throw std::invalid_argument("invalid expression");
			auto key = binops.find(op);
			if (key == binops.cend())
				throw std::invalid_argument("invalid operator");
			std::cout << key->second(lhs, rhs) << '\n';
		} catch (std::invalid_argument err) {
			std::cerr << err.what() << '\n';
		}
	}
	return 0;
}
