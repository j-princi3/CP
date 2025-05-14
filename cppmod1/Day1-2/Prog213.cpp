#include <iostream>
using namespace std;

int min(int x, int y)
{
	return(x < y ? x : y);
}

double min(double x, double y)
{
	return(x < y) ? x : y;
}

int min(int x, int y, int z)
{
	return min(x, min(y, z));
}

int main()
{
	int a = min(10, 3);
	double b = min(7.7, 13.3);
	int c = min(13, 10, 15);

	cout << " A " << a << " B " << b << " C " << c << endl;
  return 1;
}