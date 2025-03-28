#include "prog62.h"
#include "prog63.h"
#include <iostream.h>


void main()
{
	range_int_vector a(3, 12, 1);
	protected_int_vector b(10, 2, -1);
	cout << "A is " << a << endl;
	cout << "Changing A[3] to 3 " << endl;

	a[3] = 3;

	cout << "A is" << a << endl;
	cout << "B is" << b <<endl;
	int_vector c = a + b;
	cout << "A+B is" << c << endl;
}