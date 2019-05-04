/*
 * Exercise 9.45: Write a funtion that takes a string representing a name and
 * two other strings representing a prefix, such as “Mr.” or “Ms.” and a
 * suffix, such as “Jr.” or “III”. Using iterators and the insert and append
 * functions, generate and return a new string with the suffix and prefix added
 * to the given name.
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
	if (!prefix1.empty()) {
		name.insert(name.begin(), ' ');
		name.insert(name.begin(), prefix1.cbegin(), prefix1.cend());
	} 
	if (!prefix2.empty()) {
		name.insert(name.begin(), ' ');
		name.insert(name.begin(), prefix2.cbegin(), prefix2.cend());
	}
	if (!suffix.empty()) {
		name.append(" ").append(suffix);
	//	or 
	//	name.append(1, ' ').append(suffix);
	//	name.append(suffix + " ");
	}
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
