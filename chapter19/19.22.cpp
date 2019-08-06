/*
 * Exercise 19.22: Add a member of type Sales_data to your Token class.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include "Sales_data.h"

class Token {
	friend std::ostream& operator<<(std::ostream&, const Token&);
	public:
		Token() : tok(INT), ival(0) {}
		Token(const Token &t) : tok(t.tok) { copyUnion(t); }
		Token& operator=(const Token&);
		~Token() { if (tok == STR) sval.~basic_string(); }
		Token& operator=(const Sales_data&);
		Token& operator=(const std::string&);
		Token& operator=(char);
		Token& operator=(int);
		Token& operator=(double);
	private:
		enum {INT, CHAR, DBL, STR, SALES_DATA} tok; // discriminant
		union {
			char cval;
			int ival; 
			double dval;
			std::string sval;
			Sales_data sdval;
		};
		void copyUnion(const Token&);
};

// copy-assignment operator
Token&
Token::operator=(const Token &t)
{
	if (tok == STR && t.tok != STR)
		sval.~basic_string();
	else if (tok == STR && t.tok == STR)
		sval = t.sval;
	else if (tok == SALES_DATA && t.tok != SALES_DATA)
		sdval.~Sales_data();
	else if (tok == SALES_DATA && t.tok == SALES_DATA)
		sdval = t.sdval;
	else
		copyUnion(t);
	tok = t.tok;
	return *this;
}

Token&
Token::operator=(const std::string &s)
{
	// for optimizion, this check could be nested inside the else clause of
	// the following if statement. However, I belive it would be harder to read.
	if (tok == SALES_DATA)
		sdval.~Sales_data();
	if (tok == STR)
		sval = s;
	else
		new(&sval) std::string(s);
	tok = STR;
	return *this;
}

Token&
Token::operator=(const Sales_data &sd)
{
	if (tok == SALES_DATA)
		sdval = sd;
	else {
		if (tok == STR)
			sval.~basic_string();
		new (&sdval) Sales_data(sd);
	}
	tok = SALES_DATA;
	return *this;
}

Token&
Token::operator=(const char ch)
{
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SALES_DATA)
		sdval.~Sales_data();
	cval = ch;
	tok = CHAR;
	return *this;
}

Token&
Token::operator=(int i)
{
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SALES_DATA)
		sdval.~Sales_data();
	ival = i;
	tok = INT;
	return *this;
}

Token&
Token::operator=(const double d)
{
	if (tok == STR)
		sval.~basic_string();
	else if (tok == SALES_DATA)
		sdval.~Sales_data();
	dval = d;
	tok = DBL;
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
	case SALES_DATA:
		new(&sdval) Sales_data(t.sdval);
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
	case Token::SALES_DATA:
		os << t.sdval;
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
	obj = Sales_data("9-999-99999-9", 10, 25.99);
	std::cout << obj << '\n';
	Token obj2;
	obj2 = "string";
	obj = obj2;
	std::cout << obj << '\n';
	return 0;
}
