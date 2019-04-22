/*
 * Exercise 7.27: Add the move, set, and display operations to your version of
 * Screen. Test your class by executing the following code:
 *
 * 		Screen myScreen(5, 5, ’X’);
 * 		myScreen.move(4, 0).set(’#’).display(cout);
 * 		cout << "\n";
 * 		myScreen.display(cout);
 * 		cout << "\n";
 *
 * Note: the modifications to the class are made in the header file
 * By Faisal Saadatmand
 */

#include <iostream>
#include <string>
#include "Screen.h"

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std:: cout << "\n";
	return 0;
}

