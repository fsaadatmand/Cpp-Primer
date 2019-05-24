
/*
 * Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p.
 * 388) in place of the end_connection function.
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *);
void disconnect(connection);

void f(destination &d)
{
	connection c = connect(&d);
	std::shared_ptr<connection>
		p(&c, [](connection *p) { disconnect(*p); });
}

int main()
{
	return 0;
}
