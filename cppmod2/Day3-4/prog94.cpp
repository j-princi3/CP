#include <stdlib.h>
#include <iostream>
using namespace std;

class test {
  int val;
  public:
    test(int x = 0)
    {
      val = x;
    } 
    friend ostream & operator << (ostream & o, test & t)
    {
      return (cout << t.val << endl);
    }
    int operator < (test & obj)
    {
	    cout << "mymin for test Called" << endl;
      return(val < obj.val) ? val : obj.val;
    }
};

template <class T> class stack
{
	struct node
	{
		T 		data;
		node 	*next;
	}*p;

	static int countOfObjects;
	static int countOfTypes;

public :
	stack();
	~stack();
	void push(T);
	T pop();
	void display();

	static int getCountOfTypes()
	{
		return countOfTypes;
	}

	static int getCountOfObjects()
	{
		return countOfObjects;
	}
};	

template <class T> int stack<T> :: countOfObjects = 0;
template <class T> int stack<T> :: countOfTypes = 0;

template <class T> stack<T> :: stack()
{
	countOfObjects++;
	p = 0;
}

template <class T> stack<T> :: ~stack()
{
	node* run;
  countOfObjects--;
	while(p != 0)
	{
		run = p;
		p = p->next;
		delete run;
    countOfTypes--;
	}	
}

template <class T> void stack<T> :: push(T val)
{
	node*temp = new node;
	temp->data = val;
	temp->next = p;
	p = temp;	
	countOfTypes++;
}

template <class T> T stack<T> :: pop()
{
	if(p == 0)	throw "Stack Underflow\n";
	T ret;
	node *temp;
	temp = p;
	p = p->next;
	ret = temp->data;
	delete temp;
	countOfTypes--;
	return ret;
}

template <class T> void stack<T> :: display()
{
	node *run = p;
	while(run != 0)
	{
		cout << run->data << "\t";
		run = run->next;
	}	
	cout << endl;
}
void main()
{
  test a(2), b(3), c(5);
	stack <test> ts;
	ts.push(a);
	ts.push(b);
	ts.push(c);
	ts.display();
	cout << "Count of test types = " << stack <test> :: getCountOfTypes();
	cout << "\nCount of stack objects - first = " << 
		stack <test> :: getCountOfObjects() << endl; 

	stack <double> ds;
	ds.push(3.33);
	ds.push(1.11);
	ds.push(2.22);
	ds.display();

	cout << "\nCount of double types = " << stack <double> :: getCountOfTypes();
	cout << "\nCount of stack objects - first = " << 
		stack <double> :: getCountOfObjects()<< endl;

	stack <int> is;
	is.push(100);
	is.push(200);
	
	cout << "\nCount of int types = " << stack <int> :: getCountOfTypes();
	cout << "\nCount of stack objects - second " << 
		stack <int> :: getCountOfObjects()<< endl;

	stack <int> is2;
	is2.push(300);
	is2.push(400);

	cout << "\nCount of int types = " << is2.getCountOfTypes();
	cout << "\nCount of stack objects - third " << is2.getCountOfObjects()<< endl;
	cout << "\nData in double stack \n";

	try {
		for(int i = 1; ; i++)
			cout << "pop " << i <<" = " << ds.pop() << endl;
	} 
	catch(const char* s)
	{
		cout << s << endl;
	}
}
