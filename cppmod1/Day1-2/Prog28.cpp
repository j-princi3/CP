#include <iostream>
using namespace std;

void newswap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{	
	int a = 5, b = 7;
	newswap(a, b);
	cout << a << " " << b;
  return 1;
}
