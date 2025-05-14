#include <iostream>
using namespace std;

class account
{
	private:
		char name[40], acctnum[20];
		double balance;

	public:
		void init(void);
		void show(void);
		void deposit(double amt);
		void withdraw(double amt);
		double getBalance(void);
		void setBalance(double amt);
};
