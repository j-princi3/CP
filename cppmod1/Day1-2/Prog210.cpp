#include <iostream>
using namespace std;

int main()
{
  int a = 10;
  int &b = a;
  int &c = &b;		// illegal. If you uncomment, it will work.
  cout << " B is " << b << endl;
  cout << " C is " << c << endl;
  return 1;
}
