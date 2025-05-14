#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int i;
	char s[20];

	fprintf(stderr,"Enter an integer and string ");
	scanf("%d%s", &i, s);
	printf("\nOutput of printf and scanf Statement");
	fprintf(stderr, "\nInteger value is: %d ", i);
	printf("\nString value is: %s ", s);

	fflush(stdout);

	cerr << endl << "Enter an integer and string " << endl;
	cin >> i >> s;
	cout << " Output of cout and cin Statement" << endl;
	cout << endl << " Integer value is: " << i;
	cout << endl << " String  value is: " << s;
  return 1;
}
