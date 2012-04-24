#include <stdio.h>
#include <stdlib.h>

#define big long long

big r()
{
  big x = 0;
  int i;
  for (i=0;i<12;i++)
  {
    x*=10;
    x+=rand()%10;
  }

  return x;
}


