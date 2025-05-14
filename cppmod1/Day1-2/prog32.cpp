#include "prog33.h"
#include <iostream>
using namespace std;

void main()
{
	complex a(2, 4), b(3, 5), c; 		// creating objects of complex class
	cout << a << " " << b << endl;	// complex output operator
	
	c = a + b; 								// complex "+" operator
	cout << c << endl;
	
	c = a - b;								// complex "-" operator
	cout << c << endl;

	c = a * b;								// complex "*" operator
	cout << c << endl;

	c = a / b;								// complex "/" operator
	cout << c << endl;
	
	c = -a;									// complex unary minus operator
	cout << c << endl;

	a += b;									// complex "+=" operator
	cout << a << endl;

	int d;
	d = (a == b);							// complex equality  operator
	cout << d << endl;					// prints 1 if both are equal else 0

	cout << magnitude(b) << endl;		// complex magnitude function
	cout << endl << ++a; 				// complex pre increment operator
	cout << endl << a++;					// complex post increment operator
}
