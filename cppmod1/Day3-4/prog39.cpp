#include <iostream>
using namespace std;

class square
{
	int side;
	public:
		square(int s = 0)
		{
			side = s;
		}

		void print(void) const
		{
			cout << side;
		}

		void setside(int s)
		{
			side = s;
		}
};

void main()
{
   const square obj;
   obj.setside(20);
   obj.print();
}
