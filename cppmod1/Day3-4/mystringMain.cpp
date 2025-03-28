#include "mystring.h"

void main()
{
	mystring s1("Genesis");	
	mystring s2("Insoft");
	cout << "s1 = " << sizeof(s1) << endl;	
	cout << "s2 = " << sizeof(s2) << endl;	
  s1 = s2;
  s1[0] = 'D';
  cout << s1 << endl;
  cout << s2 << endl;
}