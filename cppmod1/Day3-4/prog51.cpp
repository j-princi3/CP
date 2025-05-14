#include <iostream>
using namespace std;

class parent
{
  int num1, num2;
	protected:
    int getNum1()	{	return num1; }
  
	public:
    parent(int n1 = 0, int n2 = 0) {
      num1 = n1;
      num2 = n2;
    }

    int getNum2()	{	return num2; }

    int mathOp(char type = '+') {
      cout << num1 << " " << num2 << endl;
      if(type == '*')
        return num1 * num2;
      return num1 + num2;
    }
};

class child : public parent
{
  int num3;
  public:
    child(int n1, int n2, int n3):parent(n1, n2) { num3 = n3; }
};

void main()
{
  parent pobj(5,15);
  cout << pobj.mathOp() << endl;
  child cobj(10, 20, 30);

  cout << cobj.getNum2() << endl;
  cout << cobj.mathOp('*') << endl;
  // What happens if the next two lines of code are uncommented?
  // cout << "Private data is " << cobj.num1 << endl;
  //cout << "Protected function is " << cobj.getNum1() << endl;
}
