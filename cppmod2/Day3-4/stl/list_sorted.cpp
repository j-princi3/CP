# include <iostream>
# include <list>
# include <string>

using namespace std;

void main()
{
  int i;
  list <int> lst;
  for(i = 0; i < 5; i++)
    lst.push_back(rand());

  list <int>::iterator c1_Iter;
  c1_Iter = lst.begin();
  lst.insert(++c1_Iter, 111);
  lst.push_front(222);
  cout << "Before sorting List:";
  for (c1_Iter = lst.begin(); c1_Iter != lst.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  lst.sort(); // same as lst.sort(less<int>());
  cout << "After sorting List:";
  for (c1_Iter = lst.begin(); c1_Iter != lst.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  lst.sort(greater<int>());
  cout << "After sorting with 'greater than' operation, List:";
  for (c1_Iter = lst.begin(); c1_Iter != lst.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  list <string> lststr;

  lststr.push_back("Juno");
  lststr.push_back("Genesis");
  lststr.push_front("DeShaw");
  lststr.push_back("Birla");

  list <string>::iterator c1_Iter1;

  cout << "Before sorting List:";
  for (c1_Iter1 = lststr.begin(); c1_Iter1 != lststr.end(); c1_Iter1++)
    cout << " " << *c1_Iter1;
  cout << endl;

  lststr.sort(); // lststr.sort(less<string>());
  cout << "After sorting List:";
  for (c1_Iter1 = lststr.begin(); c1_Iter1 != lststr.end(); c1_Iter1++)
    cout << " " << *c1_Iter1;
  cout << endl;

  lststr.sort(greater<string>());
  cout << "After sorting with 'greater than' operation, List:";
  for (c1_Iter1 = lststr.begin(); c1_Iter1 != lststr.end(); c1_Iter1++)
    cout << " " << *c1_Iter1;
  cout << endl;

  lststr.reverse();
  cout << "After reversing List:";
  for (c1_Iter1 = lststr.begin(); c1_Iter1 != lststr.end(); c1_Iter1++)
    cout << " " << *c1_Iter1;
  cout << endl;
}
