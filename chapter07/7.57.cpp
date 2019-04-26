/* 
 * Exercise 7.57: Write your own version of the Account class.
 * 
 * by Faisal Saadatmand
 */

#include <iostream>
#include <string>

class Account {
	public:
		Account() = default;
		Account(std::string name) : owner(name) {}
		Account(std::string name, double amt) : owner(name), amount(amt) {}
		void calculate() { amount += amount * interestRate; }
		double debt() const { return amount; }
		static double rate() { return interestRate; }
		static void rate(double);
	private:
		std::string owner;
		double amount;
		static double interestRate;
		static double initRate();
};

// define and initialize static member interestRate
double Account::interestRate = initRate();

double Account::initRate()
{
	return 0.03;  // 3 percent
}

void Account::rate(double newRate)
{
	interestRate = newRate;
}

int main()
{
	std::cout << "Initial rate: " << Account::rate() << '\n';
	Account house("faisal", 345000);
	house.calculate();
	std::cout << "Amount: " << house.debt() 
		      << " interest rate: " << house.rate() << '\n';
	Account::rate(0.025); 
	house.calculate();
	std::cout << "Amount: " << house.debt() 
		      << " interest rate: " << house.rate() << '\n';

	return 0;
}
