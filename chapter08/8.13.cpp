/*
 * Exercise 8.13: Rewrite the phone number program from this section to read
 * from a named file rather than from cin.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};

bool valid(const std::string &);
std::string format(const std::string &);

bool valid(const std::string &num)
{
	if (num.size() > 10)
		return false;
	for (const auto &c : num)
		if (!isdigit(c))
			return false;
	return true;
}

std::string format(const std::string &num)
{
	std::string formatted;
	for (decltype(num.size()) i = 0 ; i < num.size(); ++i) {
		if (i == 3 || i == 6)
			formatted.push_back('-');
		formatted.push_back(num[i]);
	}
	return formatted;
}

int main(int argc, char **argv)
{
	if (--argc != 1) {
		std::cerr << "Usage: " + std::string(*argv) + " <file_name>\n";
		return -1;
	}
	auto p = argv + 1;
	std::ifstream infile(*p);
	if (!infile) {
		std::cerr << *argv << ": Couldn't open " + std::string(*p) << std::endl;
		return -1;
	}
	std::string line, word;
	std::vector<PersonInfo> people;
	std::ostream &os(std::cout);
	while (getline(infile, line)) {
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	for (const auto &entry : people) {
		std::ostringstream formatted, badNum;
		for (const auto &nums : entry.phones) {
			if (!valid(nums))
				badNum << " " << nums;
			else
				formatted << " " << format(nums);
		}
		if (badNum.str().empty())
			os << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name
				      << " invalid number(s) " << badNum.str() << std::endl;
	}
	return 0;
}
