#include <iostream>
using namespace std;
#include "prog31.h"

// Init function initializes the account data
void  account :: init(void)
{
	cout <<"Enter name " << endl ;
	cin >> name;
	cout << "Enter account number" << endl;
	cin >> acctnum;
	cout << "Enter initial balance" << endl;
	cin >> balance;
}

// Show function displays the account data
void account :: show(void)
{
	cout << "Name is " << name << endl;
	cout << "Account number is " << acctnum << endl;;
	cout << "Balance is " << balance << endl;;
}

// Deposit function deposits some amount into the customers account
void account :: deposit(double amt) 
{
	balance += amt;
}

// Withdraw function withdraws some amount from the customers account
void account :: withdraw(double amt)
{
	balance -= amt;
}

// getBalance function returns the balance information of the customer
double account :: getBalance (void) 
{
	return balance;
}

// setBalance function updates the balance of the customer
void account :: setBalance (double amt) 
{
	balance = amt;
}

int main(void) 
{
	/* Creating an instance of account class - john object */
	account john;
	john.init();
	john.show();
	john.deposit(500);
	cout << "Modified balance " << john.getBalance() << endl;
	john.setBalance(5000);
	john.withdraw(1000);
	cout << "Updated balance " << john.getBalance() << endl;

	// Why is the statement declared below an error?
  // cout << john.name << john.acctnum << john.balance;
	return 0;
}
