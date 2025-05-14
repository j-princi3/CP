#include <iostream>
using namespace std;

int main()
{
  const int numbercount = 5;
  int *numbers = new int[numbercount];

  if(numbers != 0) {
    for(int j = 0; j < numbercount;  j++)
      numbers[j] =  j  *  j;

    for(int k = numbercount - 1; k >= 0; k--)
      cout << k << numbers[k] << endl;

    delete [] numbers;
  }
  else
    cout << "Memory allocation failed";

  return 1;
}
