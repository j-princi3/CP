#include <stdio.h>
#define square(a) a * a

inline int SQ(int x)
{
  return x * x;
}

void main( void )
{
printf("%d %d ", SQ(2+3), SQ (7-2));
}
