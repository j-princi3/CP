/*
Memory Layout in Virtual Inheritance

In order to keep track of the single instance of the grandChild object, the 
compiler will provide a virtual function table (vtable) for classes child1 and 
child2. When a grandChild object is constructed, it creates one parent instance,
a child1 instance and a child2 instance. The child1 and child2 classes have a 
virtual pointer in their vtables that stores the offset to the parent class. 
When the child1 class or the child2 class goes to access any fields of the 
parent, it uses the virtual pointer in its vtable to find the parent object and 
find the field in it. 
*/


/*
Constructors and Virtual Inheritance

Because there is only a single instance of a virtual base class that is shared 
by multiple classes that inherit from it, the constructor for a virtual base 
class is not called by the class that inherits from it (which is how 
constructors are called, when each class has its own copy of its parent class)
since that would mean the constructor would run multiple times. Instead, the 
constructor is called by the constructor of the concrete class. In the example 
below, the class grandChild directly calls the constructor for parent. If you 
need to pass any arguments to the parent constructor, you would do so using an 
initialization list:
*/

# include <iostream>
using namespace std;

#define MAX 10

class parent
{
  int parentData[MAX];
	public:
    parent()
    {
      cout << "Parent constructor called" << endl;
    }
		void m(){
			cout << "M of parent called" << endl;
		}
};

class child1: public virtual parent 
{
  int child1Data[MAX];
	public:
    child1()
    {
      cout << "child1 constructor called" << endl;
    }
		void m(){
			cout << "M of child1 called" << endl;
		}
};

class child2: public virtual parent 
{
  int child2Data[MAX];

	public:
    child2()
    {
      cout << "child2 constructor called" << endl;
    }
		void m(){
			cout << "M of child2 called" << endl;
		}
};

class grandChild : public child1, public child2
{
	public:
    grandChild() : parent(), child1(), child2() {}
		void m(){
			cout << "M of grandChild called" << endl;
    }
};

void main()
{
  grandChild obj;
	obj.m();
  cout << "Size of parent object " << sizeof(parent) << endl;
  cout << "Size of child1 object " << sizeof(child1) << endl;
  cout << "Size of child2 object " << sizeof(child2) << endl;
  cout << "Size of grandchild object " << sizeof(grandChild) << endl;
}