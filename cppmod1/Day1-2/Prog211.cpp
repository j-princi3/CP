#include <iostream>
using namespace std;

int main()
{
	int j = 20, k = 30;
	int & m = j;		 			
	int * n = &j;
	cout << j << " " << k << " " << m << endl;		
	cout << &j << " " << &k << " " << &m << " " << n << endl;
	m = k;							
	cout << j << " " << k << " " << m << endl;		
	cout << &j << " " << &k << " " << &m << " " << n << endl;
	n = &k;							
	cout << j << " " << k << " " << m << " " << *n << endl;		
	cout << &j << " " << &k << " " << &m << " " << n << endl;
  return 1;
}
