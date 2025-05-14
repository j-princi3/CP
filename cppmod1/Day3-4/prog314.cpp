#include <string.h>
#include <iostream>
using namespace std;

class complex
{
	float rpart,ipart;
	public:
		float& getRpart()
		{
			return rpart;
		}

		float& getIpart()
		{
			return ipart;
		}	

		complex(float r = 0, float i = 0)
		{
			rpart = r;
			ipart = i;
		}

		friend ostream& operator<<(ostream &o, complex &c)
		{
			o << "rpart = "<< c.rpart << "\tipart = " << c.ipart << endl;
			return o;
		}
};

class account
{
  char acctnum[20], name[20];
  double balance;
	public:
		double getbal()
		{
			return balance;
		}
	
		account(char anum[], double bal, char name[])
		{
			strcpy(acctnum, anum);
			balance = bal;
			strcpy(this->name, name);
		}

		// type cast operator to convert account object to complex object
		operator complex()
		{
			complex a;
			a.getRpart() = balance;
			a.getIpart() = 0;
			return a;
		}
};

void main()
{
	account a("AB1234",12.2,"john");
	complex b;
	b = a;					// Same as b=complex(a);
	cout << endl << b;
}