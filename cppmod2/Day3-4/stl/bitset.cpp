// compile with: /EHsc
#include <bitset>
#include <iostream>
using namespace std;

int main( )
{
   // Using the default constructor
   bitset<2> b0;
   cout << "The set of bits in bitset<2> b0 is: (" << b0 << ")" << endl;

   // Using the second member function
   bitset<6> b1(5);
   cout << "The set of bits in bitset<5> b1(6) is: (" << b1 << ")" << endl;

   bitset <6> obj1(7), obj2(8);

   // The bits have to be of the same size to be combined, otherwsie an error will result
   obj1 &= b1;
   obj2 |= b1;
   cout << "Output of &= and |= operations are: " << obj1 << "  " << obj2 << endl;

   // The template parameter N can be an expresssion
   bitset<2 * sizeof(int)> b2;
   cout << "The set of bits in bitset<2 * sizeof(int) > b2 is: (" << b2 << ")" << endl;

   // The base two representation will be truncated
   // if its length exceeds the size of the bitset
   bitset<3> b3(8);
   cout << "The set of bits in bitset<3> b3(8) is (" << b3 << ")" << endl;

   // Using the third member function with the first parameter
   string bitval4("10011");
   bitset<5> b4(bitval4);
   cout << "The set of bits in bitset<5> b4(bitval4) is (" << b4 << ")" << endl;

   // Only part of the string may be used for initialization

   // Starting at position 3 for a length of 6 (100110)
   string bitval5 ("11110011011");
   bitset<6> b5(bitval5, 3, 6);
   cout << "The set of bits in bitset<11> b5(bitval, 3, 6) is (" << b5 << ")" << endl;

   // The bits not initialized with part of the string will default to zero
   bitset<11> b6(bitval5, 3, 5);
   cout << "The set of bits in bitset<11> b6(bitval5, 3, 5) is (" << b6 << ")" << endl;

   // Starting at position 2 and continue to the end of the string
   bitset<9> b7(bitval5, 2);
   cout << "The set of bits in bitset<9> b7(bitval, 2) is (" << b7 << ")" << endl;


}