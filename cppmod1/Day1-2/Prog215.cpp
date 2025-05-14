#include <iostream>
using namespace std;

void repchar(char = '*', int = 2);

int main()
{
	repchar();
	repchar('=');
	repchar('+', 4);
  return 1;
}

void repchar(char ch, int n)
{
	for(int j = 0; j < n; j++)
	cout << ch << endl;
}
