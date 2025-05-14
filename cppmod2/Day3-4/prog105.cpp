#include <iostream>
using namespace std;

#define interface struct

interface IFace1 {
	virtual void Fun1() = 0;	
	virtual void Fun2() = 0;
	virtual void Fun3() = 0;
};

struct CImpl {
  virtual void F1()
  {
    cout << "Fun1() "<< endl;
  }
  virtual void F2()
  {
    cout << "Fun2() "<< endl;
  }
  virtual void F3()
  {
    cout << "Fun3() "<< endl;
  }
};

void main(){
  IFace1* pIFace = NULL;
  pIFace = reinterpret_cast<IFace1*> (new CImpl);
  pIFace->Fun1();
  pIFace->Fun2();
  pIFace->Fun3();
}