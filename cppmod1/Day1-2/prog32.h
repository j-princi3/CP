#include <math.h>
#include <iostream>
using namespace std;

class complex
{
	float rpart, ipart;			// Data members

	public:
		// friend function 
   	friend complex operator +(const complex &, const complex &);
		friend ostream & operator << (ostream &, complex &);	//output operator
		// comparison operator
		friend int operator == (const complex &, const complex &);
		friend double magnitude(const complex &);					// magnitude

		// binary operators
		complex operator + (complex);
		complex operator - (complex);
		complex operator * (complex);
		complex operator / (complex);
	
		complex operator - ();						// unary minus operator
		complex operator += (const complex &);	// concatenation operator
	
    //explicit complex(float = 0.0, float = 0.0); 	// explicit default arguments constructor

		complex(float = 0.0, float = 0.0); 	// default arguments constructor

		complex operator ++ ();				// pre increment operator

		complex operator ++ (int); 			// post increment operator

		// Inline functions
		float getRpart()
		{
			return rpart;
		}
		float getIpart()
		{
			return ipart;
		}
		~complex();				// destructor
};