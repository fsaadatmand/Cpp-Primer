/*
 * Exercise 17.33: Write a version of the word transformation program from §
 * 11.3.6 (p. 440) that allows multiple transformations for a given word and
 * randomly selects which transformation to apply.
 *
 * By Faisal Saadatmand
 */

#include <algorithm>
#include <ctime>
#include <exception>
#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <sstream>
#include <string>

const std::string&
random_pick(const std::string &s,
		const std::multimap<std::string, std::string> &m)
{
	static std::default_random_engine e(time(0));
	static std::bernoulli_distribution b;
	auto pos = m.equal_range(s);
	for (auto it = pos; ; ++it.first) { // no loop condition
		if (it.first == it.second)
			it = pos; // start over
		if (b(e))
			return it.first->second;
	}
}

std::multimap<std::string, std::string>buildMap(std::ifstream &map_file)
{
	std::multimap<std::string, std::string> trans_map;
	std::string key, value;
	while (map_file >> key && std::getline(map_file, value)) 
		if (value.size() > 1)
			trans_map.insert({key, value.substr(1)});
		else
			throw std::runtime_error("no rule for " + key);
	return trans_map;
}

const std::string&
transform(const std::string &s, const std::multimap<std::string, std::string> &m)
{
	if (m.count(s) > 1)
		return random_pick(s, m);
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;       // use the replacement word
	return s;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	auto trans_map = buildMap(map_file);
	std::string text;
	while (std::getline(input, text)) {
		std::istringstream stream(text);
		std::string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				std::cout << ' ';
			std::cout << transform(word, trans_map);
		}
		std::cout << '\n';
	}
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		std::cerr << "Usage: " << *argv << " <rules file> <input file>\n";
		return -1;
	}
	auto pm = *++argv;   // pointer to rules (map) file name
	auto pi = *++argv;   // pointer to input file name
	std::ifstream mapFile((pm)), inFile(pi);
	if (!mapFile || !inFile) {
		std::cerr << "Couldn't open " << ((!mapFile) ? pm : pi) << '\n';
		return -1;
	}
	word_transform(mapFile, inFile);
	return 0;
}
