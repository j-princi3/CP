#include <iostream>
using namespace std;

struct demo
{
  int x:4;
};

int main()
{
  demo d;
  d.x = 10;
  int &b = d.x;
  cout << " b is " << b << endl;
  return 1;
}
