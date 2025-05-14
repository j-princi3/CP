#include <iostream>
using namespace std;

class myComplex
{
  float rpart, ipart;
  public:
    myComplex(float = 0.0, float = 0.0);
    myComplex operator ++();
    void operator --(int);
    friend ostream & operator << (ostream &, myComplex &);    
    void operator= (myComplex);
};

myComplex::myComplex(float r, float i)
{
  rpart = r;
  ipart = i;
}

ostream & operator << (ostream & o, myComplex & a)
{
  return ( o << a.rpart << " + " << a.ipart << "i" << endl );
}

myComplex myComplex :: operator ++()
{
	return myComplex(++rpart, ++ipart);
}

void myComplex :: operator --(int)
{
	myComplex(rpart--, ipart--);
}

void myComplex::operator=(myComplex ob)
{
   rpart = ob.rpart;
   ipart = ob.ipart;
};

void main()
{
   myComplex a(1, 2), b (2, 3), c;

   // What is the warning in the following statement?
   cout << a++;

   // What is the error in the following statement? How to fix it?
   c = b = a;       
   cout << c;

   // What is the error in the following statement? How to fix it?
   c = b--;
   cout << c;
}  