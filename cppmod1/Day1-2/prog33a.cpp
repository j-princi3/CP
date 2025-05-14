#include "prog33.h"

// Constructor
complex :: complex(float r, float i) 
{
	rpart = r;
	ipart = i;
}
// Destructor
complex :: ~complex()
{
	// cout << "\n Destructor of complex class called";
}
// Output operator definition
ostream & operator << (ostream & o, complex & a)
{
	return ( o << a.rpart << " + " << a.ipart << "i" << endl );
}

// friend function Implementation
complex operator + (const complex & a, const complex & b)
{
	cout << "friend Called " << endl;
	return complex(a.rpart + b.rpart, a.ipart + b.ipart);
}

// Binary + operator definition
complex complex :: operator + (complex b)
{
	cout << "member Called " << endl;
	return complex (this->rpart + b.rpart, this->ipart + b.ipart);
}

// Binary - operator definition
complex complex :: operator - (complex b)
{
	return complex (rpart - b.getRpart(), ipart - b.getIpart());
}

// Binary * operator definition
complex complex :: operator * (complex b)
{
	return complex ((rpart * b.rpart) - (ipart * b.ipart), 
		(ipart * b.rpart) + (rpart * b.ipart));
}

// Binary / operator definition
complex complex :: operator / (complex b)
{
	complex result;

	result.rpart = ((rpart * b.rpart) + (ipart * b.ipart)) / 
		((b.rpart * b.rpart) + (b.ipart * b.ipart));
	result.ipart = ((ipart * b.rpart) - (rpart * b.ipart)) / 
		((b.rpart * b.rpart) + (b.ipart * b.ipart));

	return result;
}

// Unary - operator defintion
complex complex :: operator - ()
{
	return complex(-rpart, -ipart);
}

// Operator += definition
complex complex :: operator += (const complex & b)
{
	return complex (this->rpart += b.rpart, this->ipart += b.ipart);
}
// Pre increment operator

complex complex :: operator ++()
{
	return complex(++rpart, ++ipart);
}
// Post increment operator
complex complex :: operator ++(int)
{
	return complex(rpart++, ipart++);
}

// Equality operator definition
int operator == (const complex & a, const complex & b)
{
	return((a.rpart == b.rpart) && (a.ipart == b.ipart));
}

// Magnitude function definition
double magnitude(const complex &a)
{
	double result = sqrt(a.rpart * a.rpart + a.ipart * a.ipart);
	return result;
}
