# include "prog62.h"

void main()
{
	int_vector a(10, 1);
	
	protected_int_vector b(10, 2, -1);
	cout << "A is" << a << endl;
	cout << "B is" << b << endl;
	
	int_vector c = a + b;
	cout << "A + B is" << c << endl;
	
	cout << "Invalid subscript" <<endl;
	cout << "B[25] is" << b[25];
}
