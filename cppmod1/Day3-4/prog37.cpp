#include <iostream>
using namespace std;

class singleton 
{	
  int value;
  singleton();
  static singleton* obj;
	public:
		int getValue();
		void setValue(int val); 
		static singleton* getInstance();
};

singleton* singleton :: obj = NULL;

singleton :: singleton() {
	value = 20;
}

int singleton :: getValue() {
	return value;
}

void singleton :: setValue(int val) {
	value = val;
}

singleton * singleton :: getInstance() {
	if (obj == NULL)  {
		cout << "if block" << endl;
		obj = new singleton();
	}
	else {
		cout << "else block" << endl;			
	}
	return obj;
}

void main() {
	singleton *s1 = singleton::getInstance();
	s1->setValue(40);
	cout << "Value 1 " << s1->getValue() << endl;
	
	singleton *s2 = singleton::getInstance();
	cout << "Value 2 " << s2->getValue() << endl;
		
	s2->setValue(50);
	cout << "Value 1 " << s1->getValue() << endl;
	cout << "Value 2 " << s2->getValue() << endl;

	singleton *s3 = singleton::getInstance();
	cout << "Value 3 " << s3->getValue() << endl;
}