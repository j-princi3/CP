#include <iostream>
using namespace std;

class test_array 
{
  int x, y;		
	public:
		test_array(int xval = 0, int yval = 0)
		{
			x = xval;
			y = yval;
		}

		void show( )
		{
			cout << " x = " << x << " y = " << y << endl ;
		}
};

void main()
{	
	int i;
	test_array X[2] = {1,5};
	for(i = 0; i < 2; i++)
		X[i].show();

	test_array Y[3];
	for(i = 0; i < 3; i++)
		Y[i].show();
}	