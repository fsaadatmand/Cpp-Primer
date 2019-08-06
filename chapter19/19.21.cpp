/*
 * Exercise 19.21: Write your own version of the Token class.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Token {
	friend std::ostream& operator<<(std::ostream&, const Token&);
	public:
		Token() : tok(INT), ival(0) {}
		Token(const Token &t) : tok(t.tok) { copyUnion(t); }
		Token& operator=(const Token&);
		~Token() { if (tok == STR) sval.~basic_string(); }
		Token& operator=(const std::string&);
		Token& operator=(char);
		Token& operator=(int);
		Token& operator=(double);
	private:
		enum {INT, CHAR, DBL, STR} tok; // discriminant
		union {
			char cval;
			int ival; 
			double dval;
			std::string sval;
		};
		void copyUnion(const Token&);
};

// copy-assignment operator
Token&
Token::operator=(const Token &t)
{
	if (tok == STR && t.tok != STR)
		sval.~basic_string();
	if (tok == STR && t.tok == STR)
		sval = t.sval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token&
Token::operator=(const char ch)
{
	if (tok == STR)
		sval.~basic_string();
	cval = ch;
	tok = CHAR;
	return *this;
}

Token&
Token::operator=(int i)
{
	if (tok == STR)
		sval.~basic_string();
	ival = i;
	tok = INT;
	return *this;
}

Token&
Token::operator=(const double d)
{
	if (tok == STR)
		sval.~basic_string();
	dval = d;
	tok = DBL;
	return *this;
}

Token&
Token::operator=(const std::string &s)
{
	if (tok == STR)
		sval = s;
	else
		new(&sval) std::string(s);
	tok = STR;
	return *this;
}

void
Token::copyUnion(const Token &t)
{
	switch (t.tok) {
	case INT:
		ival = t.ival;
		break;
	case CHAR:
		cval = t.cval;
		break;
	case DBL:
		dval = t.dval;
		break;
	case STR:
		new(&sval) std::string(t.sval);
		break;
	default:
		break;
	};
}

std::ostream& operator<<(std::ostream& os, const Token& t)
{
	switch (t.tok) {
	case Token::INT:
		os << t.ival;
		break;
	case Token::CHAR:
		os << t.cval;
		break;
	case Token::DBL:
		os <<  t.dval;
		break;
	case Token::STR:
		os << t.sval;
		break;
	default:
		break;
	};
	return os;
}

int main()
{
	Token obj;
	std::cout << obj << '\n';
	obj = 'c';
	std::cout << obj << '\n';
	obj = 42;
	std::cout << obj << '\n';
	obj = 1.5;
	std::cout << obj << '\n';
	obj = "C++ Primer";
	std::cout << obj << '\n';
	obj = 32;
	std::cout << obj << '\n';
	return 0;
}
