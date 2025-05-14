#include "prog61.h"

void main()
{
	int_vector a(10, 1), b(10, 2);
	cout << "Changing A[3] to 3" << endl;
	
	a[3] = 3;
	cout << "A is " << a << " B is " << b << endl;
	
	int_vector c = a + b;
	cout << "A+B is" << c << endl;
	cout << "Shrinking A to 5 elements" << endl;
	
	a.resize(5);
	cout << "A is" << a << endl;
	cout << "Growing A to 15 elements" << endl;
	
	a.resize(15);
	cout << "A is" << a[20] << endl;
}