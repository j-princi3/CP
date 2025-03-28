#include <iostream>
using namespace std;

class account
{
	static int count;
	int val;

	public:
		account() {
			count ++;		
			val = 5;
		}

		~account() {
			count --;
		}

		static int getCount() {
			return count;
		}
};

int account:: count = 0;

void main()
{
	account cust;
	cout << "Initial count " << account::getCount() << endl;
	{
		account cust2, cust3;
		cout << "Inside count " << cust2.getCount() << endl;
	}
	cout << "Outside count " << account::getCount() << endl;
}
