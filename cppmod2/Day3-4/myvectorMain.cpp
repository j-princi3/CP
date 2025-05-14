#include "myvector_impl.h"

void main()
{
	myvector <int> i(10, 4);
  myvector <int> j(10, 4);
  myvector <int> k(10, 4);
	myvector <double> d(5, 4.55);
  k = i + j;
		
  cout << k << endl;
  cout << d << endl;
}