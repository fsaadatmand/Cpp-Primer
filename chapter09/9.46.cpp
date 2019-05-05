/*
 * Exercise 9.46: Rewrite the previous exercise using a position and length to
 * manage the strings. This time use only the insert function.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

std::string &formatName(std::string &, const std::string &,
		const std::string &, const std::string &);

std::string &formatName(std::string &name, const std::string &prefix1,
		const std::string &prefix2, const std::string &suffix)
{
	if (!prefix1.empty())
		name.insert(0, " ").insert(0, prefix1);
	if (!prefix2.empty())
		name.insert(0, " ").insert(0, prefix2);
	if (!suffix.empty())
		name.insert(name.size(), " ").insert(name.size(), suffix);
	return name;
}

int main()
{
	std::string name1{"Bjarne Stroustrup"};
	std::string name2{"Elizabeth"};
	std::string name3{"Hanah Arendt"};

	formatName(name1, "Dr.", "", "");
	formatName(name2, "Queen","", "II");
	formatName(name3, "Prof.", "", "");

	std::cout << name1 << '\n'
		      << name2 << '\n'
			  << name3 << '\n';
	return 0;
}
