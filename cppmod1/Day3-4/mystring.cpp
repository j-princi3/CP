#include "mystring.h"

// No argument constructor
mystring :: mystring()							
{
	len = 0;
	ptr = new char[len + 1];
	ptr[0] = '\0';
}

// One argument constructor
mystring :: mystring(char *p)    						
{
	len = strlen(p);
	ptr = new char[len + 1];
	strcpy(ptr, p);
}

// Two argument constructor
mystring :: mystring(char filler, int count) 				
{
	len = count;
	ptr = new char [len + 1];
	memset(ptr, filler, count);
}

// Copy constructor
mystring :: mystring(const mystring& x) 					
{
	len = x.len;
	ptr = new char [len + 1];
	strcpy(ptr, x.ptr);
}

// Destructor
mystring :: ~mystring()							
{
	delete ptr;
}

//operator =
mystring & mystring :: operator = (const mystring & x) 			
{	
	if(this != &x)
	{
		len = x.len;
		delete ptr;
		ptr = new char [len + 1];
		strcpy(ptr, x.ptr);
	}
	return (*this);
} 

mystring :: operator const char *()					
{
	return ptr;
}

// Overloaded mystring addition operator
mystring operator + (const mystring & x, const mystring & y) 		
{
	int totallen;
	char *t;
	totallen = x.len + y.len;
	t = new char [totallen + 1];
	strcpy(t, x.ptr);
	strcat(t, y.ptr);
	mystring temp(t);
	delete t;
	return temp;
}

// Overloaded mystring addition operator +=
void mystring :: operator += (const mystring & x)			
{
	int totallen;
	char *t;
	totallen = len + x.len;
	t = new char [totallen + 1];
	strcpy(t, ptr);
	strcat(t, x.ptr);
	delete ptr;
	ptr = t;
	len = totallen;
}
// Overloaded mystring addition operator
mystring operator + (const mystring & x, char ch)
{
	int totallen;
	char *t;
	totallen = x.len + 1;
	t = new char [totallen + 1];
	strcpy(t, x.ptr);
	t[x.len] = ch;
	t[x.len + 1] = '\0';
	mystring temp(t);
	delete t;
	return temp;
}

// Overloaded mystring addition operator +=
void mystring ::operator += (char ch)
{
	int totallen;
	char *t;
	totallen = len + 1;
	t = new char [totallen + 1];
	strcpy(t, ptr);
	delete ptr;
	ptr = t;
	ptr[len] = ch;
	ptr[len + 1] = '\0';
	len = totallen;
}	

// Overloaded mystring comparison operator
int mystring :: operator == (const mystring & x) const
{
	int a;
	a = strcmp(ptr, x.ptr);
	return(!a);
}

// Friend function to output objects of mystring class
ostream & operator << (ostream & strm, mystring & x)	
{	
	strm << x.ptr;
	return strm;
}

// Friend function to input objects of mystring class
istream & operator >> (istream & strm, mystring & x)
{
	char buffer[256];
	if(strm.get(buffer, 256))
		x = mystring(buffer);
	return strm;
}

// Returns the number of characters
int mystring :: length() const
{
	return len;
}

// Convert to lower case. If the function strlwr() doesn't exist, write one	
void mystring :: tolower()
{	
	strlwr(ptr);
}

// Convert to upper case. If the function strupr() doesn't exist, write one	
void mystring :: toupper()
{
	strupr(ptr);
}

char& mystring :: operator[] (int pos)
{
	return ptr[pos];
}