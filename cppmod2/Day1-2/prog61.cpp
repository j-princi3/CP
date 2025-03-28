#include "prog61.h"

int_vector :: int_vector(int size, int initial)
{
	sz = size;
	init_value = initial;
	ip = new int[size];

	for(int i = 0; i < size; i++)
		ip[i] = initial;
}

//destructor function returns our array back to the free pool.
int_vector :: ~int_vector()
{	
	delete ip;
}

//subscript operator returns a value from the array pointed to by the ip.

int& int_vector :: operator[](int x)
{
	return ip[get_offset(x)];
}

//overloaded assignment operator deletes the array in the destination,
//allocates a new array and copies the source array to it.

int_vector& int_vector :: operator = (int_vector &v)
{
	if(this != &v)
	{
		delete ip;
		ip = new int[sz = v.size()];

		for(int i = 0; i < sz; i++)
			ip[i] = v.ip[i];
	}	
	return *this;
}
int_vector :: int_vector(int_vector &v)
{
	ip = new int[sz = v.size()];

	for(int i = 0; i < sz; i++)
		ip[i] = v.ip[i];
}

//resize function allocates memory for a new array,
//copies the old values and reclaims the old array.

void int_vector :: resize(int size)
{	
	int *new_p = new int[size];

	for(int i = 0; i < size; i++)
		new_p[i] = (i < sz) ? ip[i] : init_value;

	delete ip;
	sz = size;
	ip = new_p;
}

//operator + adds two vectors of the same size.
int_vector operator +(int_vector &a, int_vector &b)
{
	if(a.size() != b.size())
	{
		cout<<"Attempt to add int vectors of unequal sizes !\n";
		exit(1);
	}

	int_vector c(a.size(), 0);

	for(int i = 0; i < a.size(); i++)
	  c.ip[i] = a.ip[i] + b.ip[i];

	return c;
}

//output operator outputs the data separated by comma (,) 
//surrounded by square brackets.
ostream & operator << (ostream & o, int_vector & v)
{
	o << "[";

	for(int i = 0; i < v.size(); i++)
	{
	if(i > 0)
			o << ",";
	o << v.ip[i];
	}
	return(o << "]");
}
