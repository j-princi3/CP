#include <iostream>
#include <map>

using namespace std;

int main( )
{
  map <int, int>::iterator m1_pIter, m2_pIter;

  map <int, int> m1, m2;
  typedef pair <int, int> Int_Pair;

  m1.insert (Int_Pair(1, 10));
  m1.insert (Int_Pair(2, 20));
  m1.insert (Int_Pair(3, 30));
  m1.insert (Int_Pair(4, 40));

  cout << "The original key values of m1 =";
  for (m1_pIter = m1.begin(); m1_pIter != m1.end(); m1_pIter++)
    cout << " " << m1_pIter -> first;
  cout << endl;

  cout << "The original mapped values of m1 =";
  for (m1_pIter = m1.begin(); m1_pIter != m1.end(); m1_pIter++)
    cout << " " << m1_pIter->second;
  cout << endl;

  pair< map<int,int> :: iterator, bool > pr;
  pr = m1.insert (Int_Pair(1, 10));

  if(pr.second == true)   
  {
    cout << "The element 10 was inserted in m1 successfully." << endl;
  }
  else   
  {
    cout << "The element 10 already exists in m1 with a key value of " <<
      (pr.first)->first << endl;
  }

  // The int version of insert
  m1.insert(--m1.end(), Int_Pair(5, 50));

  cout << "After the insertions, the key values of m1 =";
  for (m1_pIter = m1.begin(); m1_pIter != m1.end(); m1_pIter++)
    cout << " " << m1_pIter->first;
  cout << "," << endl;

  cout << "and the mapped values of m1 =";
  for (m1_pIter = m1.begin(); m1_pIter != m1.end(); m1_pIter++)
    cout << " " << m1_pIter->second;
  cout << endl;

  m2.insert (Int_Pair(10, 100));

  // The templatized version inserting a range
  m2.insert(++m1.begin(), --m1.end());

  cout << "After the insertions, the key values of m2 =";
  for (m2_pIter = m2.begin(); m2_pIter != m2.end(); m2_pIter++)
    cout << " " << m2_pIter->first;
  cout << "," << endl;

  cout << "and the mapped values of m2 =";
  for (m2_pIter = m2.begin(); m2_pIter != m2.end(); m2_pIter++)
    cout << " " << m2_pIter->second;
  cout << endl;
}
