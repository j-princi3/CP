#include <stdlib.h>
#include <iostream>
using namespace std;

class point
{
  int x, y;
	public:
		point() {}
	  point(int a, int b)
		{
      x = a;
      y = b;
		}
	
		void show()
		{
			cout << x << " ";
			cout << y << endl;
	}
  void* operator new(size_t size);
  void operator delete(void *p);
};

void* point :: operator new(size_t size)
{
	cout << "Overloaded operator new called" << endl;
	return malloc(size);
}

void point :: operator delete(void *p)
{
	cout << "Overloaded operator delete called" << endl;
	free(p);
}

int main()
{
	point *p1, *p2;
	p1 = new point(10, 20);
	if(!p1)
	{
		cout << "Allocation error" << endl;
		exit(1);
	}
	
	p2 = new point(-10, -20);
	if(!p2)
	{
		cout << "Allocation error" << endl;
		exit(1);
	}
	p1->show();
	p2->show();
	delete p1;
	delete p2;
	return 0;
}
