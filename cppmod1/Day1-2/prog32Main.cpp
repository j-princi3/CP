#include "prog32.h"
#include <iostream>
using namespace std;

void main()
{
   complex a(1, 2), b(3), c;
   c = a + b;
   cout << c<< endl;
   c = a - b;
   cout << c<< endl;
   c = a + 5;
   cout << c<< endl;
   c = 5 + a;
   cout << c << endl;
   cout << c++ << endl;
   cout << ++c << endl;
}