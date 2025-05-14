#include "prog33.h"
#include <iostream>
using namespace std;

void main()
{
   complex a(1, 2), b(3), c;
   c = a + b;
   cout << c;
   c = a - b;
   cout << c;
   c = a + 5;
   cout << c;
   c = 5 + a;
   cout << c;

//	char str[10];
//	strcpy(str, a);
//	cout << str << endl;
}