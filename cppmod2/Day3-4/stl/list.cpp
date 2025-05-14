# include <iostream>
# include <list>

using namespace std;

void main()
{
  int i;
  list <int> lst1;

  for(i = 0; i < 5; i++)
    lst1.push_back(i);

  list <int>::iterator c1_Iter;
  list <int>::const_iterator c1_cIter;
  list <int>::reverse_iterator c1_rIter;
  c1_Iter = lst1.begin();
  cout << "\nThe first element of list 1 is " << *c1_Iter << endl;

  *c1_Iter = 20;
  c1_Iter = lst1.begin();
  cout << "The first element of list 1 is now " << *c1_Iter << endl;

  // The following line would be an error because iterator is const
  // *c1_cIter = 200;

  c1_rIter = lst1.rbegin();
  cout << "The last element of list 1 is " << *c1_rIter << endl;
  cout << "List 1 data is:";
  for (c1_Iter = lst1.begin(); c1_Iter != lst1.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  // rbegin can be used to start an iteration through a list in reverse order
  cout << "List 1 data in reverse order is:";
  for (c1_rIter = lst1.rbegin(); c1_rIter != lst1.rend(); c1_rIter++)
    cout << " " << *c1_rIter;
  cout << endl;

  cout << "List 1 Max size is " << lst1.max_size() << endl;

  list <int> lst2;
  for(i = 0; i < 10; i++)
    lst2.push_back(i);

  cout << "Elements of List 2 are ";
  for (c1_Iter = lst2.begin(); c1_Iter != lst2.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  lst1.swap(lst2);

  cout << "Elements of List 1 after swapping are ";
  for (c1_Iter = lst1.begin(); c1_Iter != lst1.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  list <int>::iterator Iter;
  Iter = lst2.begin( );
  Iter++;

  lst2.erase(++Iter, lst2.end());

  cout << "Elements of List 2 after erasing are ";
  for (c1_Iter = lst2.begin(); c1_Iter != lst2.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;

  lst1.pop_front();
  lst1.pop_back();
  lst1.remove(4);

  cout << "Elements of List 1 after popping are ";
  for (c1_Iter = lst1.begin(); c1_Iter != lst1.end(); c1_Iter++)
    cout << " " << *c1_Iter;
  cout << endl;
}
