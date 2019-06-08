/*
 * Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to use
 * function-object classes in place of lambdas.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ShorterString {
	public:
		bool operator()(const std::string &s1, const std::string &s2) const
				{ return s1.size() < s2.size(); }
};

class PrintString {
	public:
		PrintString(std::ostream &o = std::cout, char c = ' ')
			: os(o), step(c) {}
		void operator()(const std::string &s) const { os << s << step; }
	private:
		std::ostream &os;
		char step;
};

class SizeComp {
	public:
		SizeComp(std::size_t n) : sz(n) {}
		bool operator()(const std::string &s) const { return s.size() >= sz; }
	private:
		std::size_t sz;
};

void elimDups(std::vector<std::string> &words)
{
	sort(words.begin(), words.end());
	auto end_uniqe = unique(words.begin(), words.end());
	words.erase(end_uniqe, words.end());
}

std::string make_plural(size_t ctr, const std::string &word,
		                            const std::string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
		const std::vector<std::string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), ShorterString());
	auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
	auto count = words.end() - wc;    // remember that the words is sorted
	std::cout << count << ' ' << make_plural(count, "word", "s")
		      << " of length "<< sz << " or longer" << '\n';
	for_each(wc, words.end(), PrintString());
}

int main()
{
	std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
		                           "over", "the", "slow", "red", "turtle"};
	constexpr std::string::size_type size = 5;
	biggies(words, size);
	std::cout << std::endl;
	return 0;
}
