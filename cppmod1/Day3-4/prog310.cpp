#include <iostream>
using namespace std;

class Test 
{
  int fixedvar;
  mutable int ordvar;
	public:
		Test (int arg1, int arg2) 
		{
			fixedvar = arg1;
			ordvar   = arg2;
		}

		void show() const 
		{
			// cout << "\n fixed var = " << fixedvar++ << endl;	// illegal
			cout << "\n ord var = " << ++ordvar << endl;				// legal
		}
};

void main()
{
	const Test const_obj(10, 20);
	const_obj.show();
}