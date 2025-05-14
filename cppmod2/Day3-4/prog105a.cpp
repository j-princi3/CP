#include <iostream>
using namespace std;

#define interface struct

interface IFace1 {
	virtual void Fun1() = 0;	
	virtual void Fun2() = 0;
	virtual void Fun3() = 0;
};

class CImpl : public IFace1{		
	public:
      virtual void Fun1() 
      {
         cout << "Fun1() "<< endl;
      }

      virtual void Fun2() 
      {
         cout << "Fun2() "<< endl;
      }

      virtual void Fun3() 
      {
         cout << "Fun3() "<< endl;
      }	
};

void main(){	
	IFace1* pIFace = new CImpl;

	pIFace->Fun1();
	pIFace->Fun2();	
	pIFace->Fun3();	
}
