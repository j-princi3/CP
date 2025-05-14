#include <iostream>
using namespace std;

class array
{
	private: 
		int *ptr;
		int size;
	public:
		array(int = 1);
		~array();
		int& operator[] (int);
		friend ostream& operator << (ostream&, const array&);
};

array :: array(int n)
{
	size = n;
	
	if(size < 0)
		throw ("Negative size for memory allocation not allowed");

	ptr = new int[size];
	if (ptr == 0)
		throw("Out of memory");

	for(int i = 0; i < size; i++)
		ptr[i] = 0;
}

array :: ~array()
{
	delete [] ptr;
}

int& array :: operator[] (int x) 
{
	if((x < 0) || (x >= size))	
		throw x;

	return ptr[x];
}

ostream & operator << (ostream& os, const array& a)
{
	cout << "The array:\n";
	for(int i = 0; i < a.size; i++)
		os  << '[' << i << ']' << " " << a.ptr[i] << endl;

	return os;
}

int main()
{
	cout << "Input the array size ";
	int length;
	cin >> length;				// Press ctrl z to encounter eof

	while(!cin.eof())
	{
		try
		{
			array a(length);
			cout << "Enter an index and a value: ";
			int index, value;
			cin >> index >> value;

			while(!cin.eof())
			{
				a[index] = value;
				cout << a << endl;
				cout << "Enter next index and value: ";
				cin >> index >> value;
			}
		}
		catch(const char* message)
		{
			cerr << message << endl;
		}
		catch(int m)
		{
			cerr << "Invalid index : " << m << endl;
		}
		cout << "Enter next array length: ";
		cin >> length;
	}
	return 0;
}
