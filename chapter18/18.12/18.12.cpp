/*
 * Exercise 18.12: Organize the programs you have written to answer the
 * questions in each chapter into their own namespaces. That is, namespace
 * chapter15 would contain code for the Query programs and chapter10 would
 * contain the TextQuery code. Using this structure, compile the Query code
 * examples.
 *
 * By Faisal Saadatmand
 */

/*
 * To build:
 * 	make
 *
 * To clean:
 * 	make clean
 *
 * To run:
 * ./18.12 <filename>
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Query.h"
#include "QueryHistory.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"
#include "buildQuery.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << *argv << " <filename>\n";
		return -1;
	}
	std::ifstream text(*++argv);
	if (!text) {
		std::cerr << "Couldn't open " << *argv << '\n';
		return -1;
	}
	chapter12::TextQuery tq(text);
	std::string input;
	chapter15::Query query;
	chapter15::QueryHistory history;
	while (true) {
		std::cout << "Search for word ($ to list history; q to quit): ";
		if (!std::getline(std::cin, input) || input == "q")
			break;
		else if (input == "$") { // list history
			history.list();
			continue;
		}
		if (!input.empty()) {
			try {
				std::stringstream line(input);
				query = buildQuery(line, query, history);
				history.add(query);
				std::cout << query.eval(tq);
			} catch (std::invalid_argument &err) {
				std::cerr << err.what() << '\n';
			}
		}
	}
	return 0;
}
