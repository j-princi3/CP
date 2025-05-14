#include <iostream>
using namespace std;

void repchar()
{
	for (int j = 0; j < 2; j++)
		cout << '*' << endl;
}

void repchar (char ch)
{
	for (int j = 0; j < 4; j++)
		cout << ch << endl;
}

void repchar (char ch, int  n)
{
	for(int j = 0; j < n; j++)
		cout << ch << endl;
}

int main()
{
	repchar();
	repchar('=');
	repchar('+',6);
  return 1;
}