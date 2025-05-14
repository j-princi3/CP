#include <string.h>
#include "mystring.h"
#include <iostream>
using namespace std;

class bank
{
  int & acctnum;
  mystring name;
  double balance;
  const float int_rate;	
	public:
		bank(int &, mystring, double, float);
		void show();
};

bank :: bank(int & a, mystring acct_name, double new_bal, float roi)
:	acctnum(a),  int_rate(roi)
{
	name = acct_name;
	balance = new_bal;
}

/*bank :: bank(int & a, mystring acct_name, double new_bal, float roi)
{
	acctnum = a;
	name =  acct_name;
	balance = new_bal;
	int_rate = roi;
}*/

void bank :: show()
{
	cout << "Name is " << name << endl;
	cout << "Acctnum is " << acctnum << endl;
	cout << "Balance is " << balance << endl;
	cout << "Interest rate is " << int_rate << endl;
}

void main()
{
	int id = 2;
	mystring cname("john");
	bank customer(id, cname, 5555.5, 12.5);
	customer.show();
}