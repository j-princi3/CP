#include <iostream>
using namespace std;

void init(int *x)
{
	cout<<"In init method "<<endl;
}

void f(char*) {
  cout << "char * called " << endl;
}

void f(const char*){
  cout << "const char * called " << endl;
}

void main(int argc,char *argv[])
{
	int num1 = 10;
	int num2 = 3;

	cout<<"result1 is " << static_cast<double>(num1)/num2 <<endl;

	void init(int *pa);
	const int a1 = 10;

	// init(&a1); 	// error

	init(const_cast<int*>(&a1));

  char* p = 0;
  f(p); 
  f(const_cast<const char*>(p)); 

  int i = 3;
  const int& j = i;
  const int* k = &i;

  const_cast<int&>(j) = 5;
  *const_cast<int*>(k) = 10;

  cout<< j  << " " << *k << " " << i << endl;
}	
