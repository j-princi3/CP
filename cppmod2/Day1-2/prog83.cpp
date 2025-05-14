#include <string.h>
#include <iostream>
using namespace std;

class Exception
{
	char message[100];
	public:
		Exception(){}

		Exception(char * m)
		{
			strcpy(message, m);
		}
		char * getMessage()
		{
			return message;
		}
		~Exception(){}
};

class withdrawException : public Exception
{
	public:
		withdrawException():Exception() {}
		withdrawException(char * err):Exception(err) {}
};

class duplicateAccNoException : public Exception
{
	int actNo;
	
	public:
		duplicateAccNoException():Exception() {}
		duplicateAccNoException(int act_no, char * message) : Exception(message) 
		{
			this->actNo = act_no;
		}
		int getActNo()
		{
			return actNo;
		}
};

const int minBal = 1000;
const int acc_no[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

class Account
{
	int accno;
	char name[30];
	double balance;
	void checkDupAccNo(int);

	public:
		void getData(void);
		void withDraw(double);
		void Deposit(double);
		void Show();
};

void Account :: checkDupAccNo(int num) 
{
	for(int i = 0; i < 10; i++)
	{
		if(acc_no[i] == num)
			throw duplicateAccNoException(num, "Existing account");
	}
}

void Account :: getData() 
{
	while(1)
	{
		cout << "Enter Account number: ";
		cin >> accno;

		try
		{
			checkDupAccNo(accno);
			break;
		}
		catch(duplicateAccNoException d)
		{
			throw Exception("Something");
		}
	}

	cin.ignore();
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter Initial Balance: ";
	cin >> balance;
}

void Account :: withDraw(double amt)
{
	double b = balance - amt;

	if (b < minBal)
		throw withdrawException
		("Cannot withdraw more than minimum Balance");
	else
		balance = b;
}

void Account :: Deposit(double amt)
{
	balance += amt;
}

void Account::Show()
{
	cout << "Account No: " << accno << endl;
	cout << "Name: "<< name << endl;
	cout << "Balance: "<< balance << endl;
}

void main()
{
	Account A;
	try
	{
		A.getData();
		A.Deposit(500);
		A.withDraw(5000);
		A.Show();
	}
	
	catch(duplicateAccNoException m)
	{
		cout << m.getMessage() << ": " << m.getActNo() << endl;
	}
	catch(withdrawException d)
	{
		cout << d.getMessage() << endl;
	}
	catch(Exception m)
	{
		cout << m.getMessage() <<  endl;
	}
	catch(...)	// Catch all
	{
		cout << "\n something went wrong";
	}	
}














