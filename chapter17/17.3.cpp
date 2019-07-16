/*
 * Exercise 17.3: Rewrite the TextQuery programs from § 12.3 (p. 484) to use a
 * tuple instead of the QueryResult class. Explain which design you think is
 * better and why.
 *
 * By Faisal Saadatmand
 */

/*
 * The design that uses the QueryResult class is better. It is easier to read,
 * expand and maintain.
 */

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

class TextQuery {
	friend class QueryResult;
	public:
		using line_no = std::vector<std::string>::size_type;
		using query_result = std::tuple<std::string,
			   std::shared_ptr<std::set<TextQuery::line_no>>,
			   std::shared_ptr<std::vector<std::string>>>;
		TextQuery(std::ifstream &);
		query_result query(const std::string &) const;
	private:
		std::shared_ptr<std::vector<std::string>> file;
		std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];    // lines is a shared pointer
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}

TextQuery::query_result
TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		//not found
		return query_result(sought, nodata, file);
	return query_result(sought, loc->second, file);
}


std::string make_plural(std::size_t ctr, const std::string &word,
		                             const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

std::ostream &print(std::ostream &os, const TextQuery::query_result &qr)
{
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " "
	   << make_plural(std::get<1>(qr)->size(), "times", "s") << '\n';
	for (auto num : *std::get<1>(qr))
		os << "\t(line " << num + 1 << ") "
		   << *(std::get<2>(qr)->begin() + num) << std::endl;
	return os;
}

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	while (true) {
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin >> s) || s == "q")
			break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " infile\n";
		return -1;
	}
	std::ifstream inFile(*++argv);
	if (!inFile) {
		std::cerr << "could not open " << *argv << '\n';
		return -1;
	}
	runQueries(inFile);
	return 0;
}
