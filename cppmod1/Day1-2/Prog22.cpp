#include <stdio.h>

inline int min(int x, int y)
{
	return(x < y ? x : y);
}

int main()
{	
	int a = 10, b=25;
	int result = min(a, b);
  printf("%d", result);
	return 1;
}
