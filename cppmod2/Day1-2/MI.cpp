#include <iostream>
using namespace std;

class A
{
	public:
		void M(){
			cout << "M of A called" << endl;
		}
};
class B 
{
	public:
		void M(){
			cout << "M of B called" << endl;
		}
};
class C : public A, public B
{
	public:
		void M(){
			cout << "M of c called" << endl;
		}
};

void main()
{
	C obj;
	obj.A::M();
}