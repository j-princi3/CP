#include <iostream>
#include <deque>
#include <string>

using namespace std;

void printcontents (deque <string> dq)
{
  deque <string>::iterator pdeque;
  cout <<"\nData is: ";

  for(pdeque = dq.begin(); pdeque != dq.end(); pdeque++)
    cout << *pdeque << " ";
}

void main()
{
  int i;
  string data[5] = {"Juno", "ADP", "Genesis"};
  deque <string> dq;

  for(i = 0; i < 5; i++)
    dq.push_back(data[i]);

  printcontents (dq);
  cout << "\nData at position 1 is: " << dq.at(1);
  dq.pop_back();
  dq.push_front("Infosys");
  printcontents (dq);

  deque <string>::iterator Iter;

  Iter = dq.begin();
  dq.insert(++Iter, 2, "Barion");
  printcontents (dq);

  deque <string> :: reverse_iterator rIter;

  cout << "\nThe reversed deque is: ";
  for(rIter = dq.rbegin(); rIter != dq.rend(); rIter++)
    cout << *rIter << " ";

  cout << endl;
}

