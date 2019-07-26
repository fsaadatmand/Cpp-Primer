/*
 * Exercise 18.5: Modify the following main function to catch any of the
 * exception types shown in Figure 18.1 (p. 783):
 *
 * 	int main() {
 * 		// use of the C++ standard library
 * 	}
 *
 * The handlers should print the error message associated with the exception
 * before calling abort (defined in the header cstdlib) to terminate main.
 *
 * By Faisal Saadatmand
 */

#include <cstdlib>
#include <iostream>
#include <exception>

int main()
{
	try {
		// use of the C++ library
	} catch (std::length_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::domain_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::logic_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::range_error &e){
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::underflow_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::overflow_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::bad_cast &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (std::bad_alloc &e) {
		std::cout << e.what() << std::endl;
		abort();
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		abort();
	}
	return 0;
}
