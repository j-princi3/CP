#include <iostream>
using namespace std;

class rectangle 
{
	int left, top, right, bottom;
	public:
    rectangle(int l, int t, int r, int b)
    {
      left = l;
      top = t;
      right = r;
      bottom = b;
    }
    int getLeft() const;
	  int getTop()  const 			{ return top; }
		int getRight()  const 		{ return right; }
		int getBottom()  const 		{ return bottom; }
};

inline int rectangle :: getLeft() const
{
	return left;		
}

void main()
{
   rectangle obj(10, 20, 30, 40);
   cout << obj.getLeft();
}
