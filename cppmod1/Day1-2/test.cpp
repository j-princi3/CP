#include <iostream>
using namespace std;

extern "C" int add(int, int);

int add(int a, int b, int c)
{
  return a+b+c;	
}

int main(int argc, char *argv[])
{
	cout << "Add of 2 numbers is " << add(5, 10) << endl;	
  cout << "Add of 3 numbers is " << add(5, 10, 15) << endl;	
	return 0;
}
