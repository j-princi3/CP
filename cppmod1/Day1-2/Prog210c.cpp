#include <iostream>
using namespace std;

int main()
{
  int a = 10,	*x = &a;
  int &b = a;
  // int *c = b;		// illegal
  int *c = &b;		// legal
  // int &d = x;		// illegal
  int &d = *x;		// legal

  cout<< "A is "<< a << endl;
  cout<< "B is "<< b << endl;
  cout<< "C is "<< *c << endl;
  return 1;
}
