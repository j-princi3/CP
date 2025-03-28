#include <string.h>
#include <iostream>
using namespace std;

class  mystring 
{
  char *ptr;                // pointer to allocated space
  int len;   								// current length of string
	public:
		mystring();	    						// zero argument constructor
		mystring(char *);		    				// one argument constructor
		mystring(char, int);	          // two argument constructor
		mystring(const mystring &);	    // copy constructor
		~mystring();                    // destructor
		mystring & operator = (const mystring &);	// assignment operator
		operator const char *();				// conversion function

		// Concatenation functions
		friend mystring operator + (const mystring &, const mystring &);
		void operator += (const mystring &);
		friend mystring operator + (const mystring &, char);
		void operator += (char);

		// Access operator
		char & operator [] (int); 				

		// Output and input operator
		friend ostream & operator << (ostream &, mystring &);
		friend istream & operator >> (istream &, mystring &);

		// Comparison function
		int operator == (const mystring &) const;
		int operator != (const mystring &) const;
		int length() const;					// value return function

		// Case conversion function
		void tolower();
		void toupper();
};