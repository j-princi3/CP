#include <iostream>
using namespace std;

struct base
{
	virtual void draw() {
		cout << "Base draw" << endl;
	}
};

struct der1 : base
{
	virtual void draw() {
		cout << "Derived 1 draw" << endl;
	}

	void fn1() { 
		cout << "function 1" << endl;
	}
};

struct der2: base
{
	void fn2() { 
		cout << "function 2" << endl;
	}
};

void main()
{
	base *p[2];
	der1 derobj1;
	der2 derobj2, *pder2;

	p[0] = &derobj2;
	p[1] = &derobj1;

	for(int i = 0; i < 2; i++) {
    p[i]->draw();
    if(dynamic_cast<der1 *>(p[i])) {
      cout << "If block " << endl;
      dynamic_cast<der1 *>(p[i])->fn1();
    }
    else if(pder2 = dynamic_cast<der2 *>(p[i])) {
      cout << "Else if block " << endl;
      pder2->fn2();
    }
  }	
}