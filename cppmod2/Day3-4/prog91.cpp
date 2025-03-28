#include <iostream>
using namespace std;

class test {
  int val;
  public:
    test(int x)
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

// mymin for ints
/*int mymin(int a, int b)
{
	cout << "mymin for ints Called" << endl;
    return(a < b) ? a : b;
}

// mymin for longs
long mymin(long a, long b)
{
	cout << "mymin for longs Called" << endl;
    return(a < b) ? a : b;
}

// mymin for chars
char mymin(char a, char b)
{
	cout << "mymin for chars Called" << endl;
    return(a < b) ? a : b;
}*/
template <class T> T mymin(T a, T b )
{
	cout << "template Called" << endl;
    return(a < b) ? a : b;
}

void main()
{
	cout << mymin(10, 20) << endl;
	cout << mymin(2.3, 5.2) << endl;
	cout << mymin('a', 'b') << endl;

	test a(1), b(3);
	cout << mymin(a, b) << endl;
}