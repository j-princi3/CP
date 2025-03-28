#include <iostream>
using namespace std;

class empty{};

void main()
{
	empty e;
	cout << "Size of a empty class: "<<sizeof(e) <<endl;

	empty e1[5];
	for (int i = 0;i < 5 ;i++)
		cout << "Address of: "<<&e1[i] <<endl;

}