/*
 * Exercise 12.14: Write your own version of a function that uses a shared_ptr
 * to manage a connection.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *);
void disconnect(connection);

void end_connection(connection *p) { disconnect(*p); }

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection> p(&c, end_connection);
}

int main()
{
	return 0;
}
