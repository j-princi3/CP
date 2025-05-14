#include <iostream>
#include <stack>
#include <string>

using namespace std ;

void main()
{
  string data[5] = {"Juno", "ADP", "Genesis", "Microsoft", "Satyam"};
  stack <string> stk;
  int i;

  cout << "stack size is " << stk.size() << endl;

  for(i = 0; i < 5; i++)
    stk.push(data[i]);

  cout << "Top element: " << stk.top() << endl;
  stk.pop();
  cout << "stack size is " << stk.size() << endl;  
  cout << "Top element afer pop: " << stk.top() << endl;

  stack <int> stk1;
  cout << "stack size is " << stk1.size() << endl;

  for(i = 0; i < 5; i++) {
    int j = rand();
    cout << j << " ";
    stk1.push(j);
  }

  cout << "\nTop element: " << stk1.top() << endl;
  stk1.pop();
  cout << "Top element afer pop: " << stk1.top() << endl;
}
