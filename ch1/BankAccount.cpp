// bankaccount.cpp
// demostrates basic OOP Syntax

#include<iostream>
using namespace std;

class BankAccount
{
private:
	double balance;					// account balance
public:
	BankAccount(double openingBalance)
	{
		balance = openingBalance;
	}

	void deposit(double amount)
	{
		balance = balance + amount;
	}

	void withdraw(double amount)
	{
		balance = balance - amount;
	}

	void display()
	{
		cout << "Balance=" << balance << endl;
	}
};

int main()
{
	BankAccount ba1(100.00);		// create

	cout << "Before transactions, ";
	ba1.display();

	ba1.deposit(74.35);				// make deposit
	ba1.withdraw(20.00);			// make withdraw

	cout << "After transactions,";	// display balance
	ba1.display();
	return 0;
}

