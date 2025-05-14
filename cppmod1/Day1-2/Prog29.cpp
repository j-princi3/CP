#include <stdio.h>

static int a[100] = {0};

int & subscript(int array[], int x, int y)
{
   return array[x*10+y];
}

int main()
{
	subscript(a, 4, 3) = 25;
	printf("%d %d\n", a[43], subscript(a, 4, 3));
  return 1;
}
