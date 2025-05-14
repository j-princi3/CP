#include <stdio.h>

inline int min(int x, int y)
{
	return(x < y ? x : y);
}

int main()
{
	int(*min_func)(int,int)=min;
	printf("%d\n", min_func(75,33));
  return 1;
}
