#include <iostream>
#include <vector>

using namespace std ;

void main()
{
  int i;
  vector <int> iv;
  cout << "Vector is empty: " << iv.empty() << endl;

  for(i = 0; i < 5; i++) {
    iv.push_back(i);
    if(i == 0)
      cout << "Elements are : ";
    cout << iv.at(i) << "  ";  
  }

  cout << endl;
  
  const int &j = iv.at(0);
  int &k = iv.at(1);
  cout << "Vector size is: " << iv.size() << endl;
  cout << "Vector maximum size is: " << iv.max_size()
       << endl;
  cout << "Vector's capacity is: " << iv.capacity() << endl;
  cout << "First element is " << j << endl;
  cout << "Second element is " << k << endl;
  
  vector <double> dv;  

  dv.push_back(10.5);
  dv.push_back(20.6);

  cout << "Vector size is: " << dv.size() << endl;
  cout << "Vector maximum size is: " << dv.max_size() << endl;

  cout << "First element is " << dv.at(0) << endl;
  cout << "Second element is " << dv.at(1) << endl;

  vector <int> iv1;
  for(i = 10; i <= 20; i++)
    iv1.push_back(i);

  iv1.swap(iv);

  cout << "First element of v1 is " << iv1.at(0) << endl;
  cout << "Second element is " << iv1.at(1) << endl;

  // Why does the following statement result in an error?
  // cout << "The eight element is " << iv1.at(8) << endl;

  cout << "First element is " << iv1.front() << endl;
  cout << "Last element is " << iv1.back() << endl;

  vector <int> v1;
  vector <int>::iterator Iter;

  for(i = 50; i < 55; i++)
    v1.push_back(i);

  cout << "v1 = " ;
  for ( Iter = v1.begin(); Iter != v1.end(); Iter++ )
    cout << *Iter << " ";
  cout << endl;

  v1.assign(v1.begin() + 1, v1.begin() + 3);
  cout << "v1 = ";
  for (Iter = v1.begin(); Iter != v1.end(); Iter++)
    cout << *Iter << " ";
  cout << endl;

  v1.assign( 7, 4 ) ;
  cout << "v1 = ";
  for (Iter = v1.begin(); Iter != v1.end(); Iter++)
    cout << *Iter << " ";
  cout << endl;

  iv1.erase(iv1.begin(), iv1.begin() + 2);
  cout << "First element is " << iv1.at(0) << endl;
}
 
