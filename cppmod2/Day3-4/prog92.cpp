#include <iostream>
using namespace std;

# define square(a)  a * a

void main() 
{
	int i, j, k, m = 4;

	i = 16 / square(2);
	j = square(4 + 3);
	k = square(++m);

	cout << i << " " << j << " " << k << " " << m;
}